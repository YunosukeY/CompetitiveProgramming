#include <stdio.h>
#include <ctype.h>
#include <cv.h>
#include <highgui.h>
#include <curses.h>
#include "get_contour.h"

#define PORT "/dev/ttyACM0" //適宜変更のこと
#include "serial2016.h"

#define CAMERA_CENTER_H 97 //カメラサーボの垂直方向中央値（キャリブレーションに利用）
#define CAMERA_CENTER_V 87 //カメラサーボの垂直方向中央値（キャリブレーションに利用）
#define MOTOR_DEFAULT_L 119 //左モータのデフォルト値（キャリブレーションに利用）
#define MOTOR_DEFAULT_R 133 //右モータのデフォルト値（キャリブレーションに利用）
#define CAMERA_INIT_V 70 //カメラサーボの垂直方向初期値
#define CAMERA_INIT_H 90 //カメラサーボの水平方向初期値

#define CAMERA_CENTER_X 120

void go_straight() {motor(140, 140)};
void rotate_R() {motor(140, 128)};
void rotate_L() {motor(128, 140)};

void on_mouse(int event, int x, int y, int flags, void *param);

int main(int argc, char **argv) {
  CvCapture *capture = NULL;
  IplImage *frame;     // キャプチャ画像 (RGB)
  IplImage *frameHSV;   // キャプチャ画像 (HSV)
  IplImage* framePT;    // 透視変換画像 (RGB)
  IplImage* framePTHSV; // 透視変換画像 (HSV)

  IplImage* mask;      // 指定値によるmask (１チャネル)
  IplImage* contour;   // GetLargestContour() の結果
  IplImage** frames[] = {&frame, &frameHSV};
  IplImage** framesPT[] = {&framePT, &framePTHSV};
  contourInfo topContoursInfo[CONTOURS];
  int key;

  init();

  // 実習項目5.0で計測したモーターの中央値をmotor_onに、サーボの中央値をcamera_onにそれぞれセットする
  motor_on(MOTOR_DEFAULT_L, MOTOR_DEFAULT_R); // モーター静止パルス幅のキャリブレーション
  camera_on(CAMERA_CENTER_V,CAMERA_CENTER_H);    // カメラアングルキャリブレーション

  camera_horizontal(CAMERA_INIT_H); // 水平方向のカメラ角度を初期値に
  camera_vertical(CAMERA_INIT_V); // 垂直方向のカメラ角度を初期値に

  // 赤系のHSV色．各自チューニングすること
  uchar minH = 110, maxH = 140;
  uchar minS = 100, maxS = 255;
  uchar minV =  60, maxV = 255;
  CvMat *map_matrix;
  CvPoint2D32f src_pnt[4], dst_pnt[4];

  src_pnt[0] = cvPoint2D32f(181.0, 199.0);
  src_pnt[1] = cvPoint2D32f(110.5, 199.0);
  src_pnt[2] = cvPoint2D32f(104.7, 240.0);
  src_pnt[3] = cvPoint2D32f(184.2, 240.0);
  dst_pnt[0] = cvPoint2D32f(132.5, 240.0);
  dst_pnt[1] = cvPoint2D32f(107.5, 240.0);
  dst_pnt[2] = cvPoint2D32f(107.5, 260.0);
  dst_pnt[3] = cvPoint2D32f(132.5, 260.0);
  map_matrix = cvCreateMat (3, 3, CV_32FC1);
  cvGetPerspectiveTransform (src_pnt, dst_pnt, map_matrix);

  if (argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
    capture = cvCaptureFromCAM(argc == 2 ? argv[1][0] - '0' : -1);
  if (capture == NULL) {
    printf("not find camera\n");
    return -1;
  }
  // 解析速度向上のために画像サイズを下げる
  cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, 320);
  cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, 240);

  frame = cvQueryFrame(capture);
  frameHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
  framePT = cvCreateImage(cvSize(240,270), IPL_DEPTH_8U, 3);
  framePTHSV = cvCreateImage(cvGetSize(framePT), IPL_DEPTH_8U, 3);
  mask = cvCreateImage(cvGetSize(framePT), IPL_DEPTH_8U, 1);
  contour = cvCreateImage(cvGetSize(framePT), IPL_DEPTH_8U, 3);

  cvNamedWindow("src", CV_WINDOW_AUTOSIZE);
  cvNamedWindow("dst", CV_WINDOW_AUTOSIZE);
  cvNamedWindow("contour", CV_WINDOW_AUTOSIZE);
  cvMoveWindow("src", 60,480);
  cvMoveWindow("dst", 380,480);
  cvMoveWindow("contour", 700,480);
  cvSetMouseCallback("src", on_mouse, (void *)frames);
  cvSetMouseCallback("dst", on_mouse, (void *)framesPT);
  cvSetMouseCallback("contour", on_mouse, (void *)framesPT);

  int front = 0;
  while (1) {
    frame = cvQueryFrame(capture);
    cvCvtColor(frame, frameHSV, CV_RGB2HSV);
    cvWarpPerspective (frame, framePT, map_matrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(100));
    cvCvtColor(framePT, framePTHSV, CV_RGB2HSV);
    cvShowImage("src", frame);
    cvShowImage("dst", framePT);
    GetMaskHSV(framePT, mask, minH, maxH, minS, maxS, minV, maxV);
    GetLargestContour(framePT, mask, contour, topContoursInfo);
    cvShowImage("contour", contour);
    key = cvWaitKey(1);

    // 回転 ... 18 degree / sec
    // 直進 ... 10 cm / sec
    // 1px =  1/3 cm
    if(topContoursInfo[0].area > 0) {
      /// 赤い物体を見つけた場合
      CvBox2D oblique = topContoursInfo[0].oblique; // 認識した物体を囲む長方形
      int x = oblique.center.x;                            // 認識した物体の画面内のx座標(0~239)
      int y = oblique.center.y;                            // 認識した物体の画面内のy座標(0~269)
      int w = oblique.size.width;
      int h = oblique.size.height;
      int angle = abs(oblique.angle);
      if (h < w) angle = angle - 90;

      if (abs(x - 120) < 6 && abs(angle) > 84) { // 正面にいる場合
        go_straight();
        front = 1;
      } else {
        // 回転方向を決定
        if (angle < 0) rotate_R();
        else rotate_L();
        // 回転
        sleep(abs(angle) / 15);
        // 垂直二等分線に垂直に直進
        go_straight();
        sleep(((279 - y) / 3) * cos(angle * acos(-1) / 180) / 10);
        // 赤い物体の方を向く
        if (angle < 0) rotate_L();
        else rotate_R();
        sleep(abs(angle) / 15);
      }
      front = 0;
    } else {
      /// 赤い物体が見つからなかった場合
      if (front) { // 正面
        sleep(3);
      } else {
        int i;
        for(i = 0; i < 40; i++) { // 1回転
          frame = cvQueryFrame(capture);
          cvCvtColor(frame, frameHSV, CV_RGB2HSV);
          cvWarpPerspective (frame, framePT, map_matrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll (100));
          cvCvtColor(framePT, framePTHSV, CV_RGB2HSV);
          cvShowImage("src", frame);
          cvShowImage("dst", framePT);
          GetMaskHSV(framePT, mask, minH, maxH, minS, maxS, minV, maxV);
          GetLargestContour(framePT, mask, contour, topContoursInfo);
          cvShowImage("contour", contour);
          key = cvWaitKey(1);
          if(topContoursInfo[0].area <= 0) { // 赤い物体が見えていない間は回転
            rotate_R();
            sleep(0.5);
          } else {
            break;
          }
        }

        if (i == 40) { // 1周しても見つからない場合
          go_straight();
          sleep(5);
        }
      }
      front = 0;
    }

    if (key == 'q') break;
  }

  finalize();
  cvDestroyWindow("src");
  cvDestroyWindow("contour");
  cvReleaseImage(&frameHSV);
  cvReleaseImage(&framePTHSV);
  cvReleaseImage(&mask);
  cvReleaseImage(&contour);
  cvReleaseCapture(&capture);
  return 0;
}

void on_mouse(int event, int x, int y, int flags, void *frames)
{
  CvScalar BGR, HSV;
  if (event == CV_EVENT_MOUSEMOVE) {
    IplImage* rgb_image = *(((IplImage***)frames)[0]);
    IplImage* hsv_image = *(((IplImage***)frames)[1]);
    if(y < rgb_image->height && x < rgb_image->width &&
      y < hsv_image->height && x < hsv_image->width)
    {
      BGR = cvGet2D(rgb_image, y, x);
      HSV = cvGet2D(hsv_image, y, x);
      printf("(%3d,%3d): RGB=(%3.0f,%3.0f,%3.0f) HSV=(%3.0f,%3.0f,%3.0f)\n",
       x, y, BGR.val[2], BGR.val[1], BGR.val[0],
       HSV.val[0], HSV.val[1], HSV.val[2]);
    }
  }
}