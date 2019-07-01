// https://www.trifields.jp/how-to-install-opencv-on-ubuntu-2742

#include <bits/stdc++.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "dump.hpp"
using namespace std;
using namespace cv;

using ComplexArg = double;

/******************** 幾何の基本要素 ********************/

const ComplexArg INF = 1e12;

// 点
typedef complex<ComplexArg> P;

// 直線
struct L : public vector<P>{
  L(const P &a, const P &b){
    push_back(a); push_back(b);
  }
};

// 多角形
typedef vector<P> G;

// 円
struct C {
  P p; ComplexArg r;
  C(const P &p_, ComplexArg r_):p(p_),r(r_){}
};

/******************** 描画用関数 ********************/

// corner value
struct CValue{
  ComplexArg xmin,xmax,ymin,ymax;

  CValue(void):xmin(INF), xmax(-INF), ymin(INF), ymax(-INF){}
  CValue(const P& p){
    this->xmin = this->xmax = p.real();
    this->ymin = this->ymax = p.imag();
  }
  CValue(ComplexArg xmin_, ComplexArg xmax_, ComplexArg ymin_, ComplexArg ymax_):
    xmin(xmin_), xmax(xmax_), ymin(ymin_), ymax(ymax_){}

  void update(const CValue &a){
    this->xmin = min(this->xmin, a.xmin);
    this->xmax = max(this->xmax, a.xmax);
    this->ymin = min(this->ymin, a.ymin);
    this->ymax = max(this->ymax, a.ymax);
  }
};

// P (complex<ComplexArg>)
CValue calcCornerEach(const P &p){
  return CValue(p);
}
// L
CValue calcCornerEach(const L &l){
  CValue res;
  for(auto p : l){
    res.update(CValue(p));
  }
  return res;
}
// G
CValue calcCornerEach(const G &g){
  CValue res;
  for(auto p : g){
    res.update(CValue(p));
  }
  return res;
}
// vector<L>
CValue calcCornerEach(const vector<L> &ls){
  CValue res;
  for(auto l : ls){
    res.update(calcCornerEach(l));
  }
  return res;
}
// C
CValue calcCornerEach(const C &c){
  return CValue(c.p.real()-c.r, c.p.real()+c.r, c.p.imag()-c.r, c.p.imag()+c.r);
}

// base case
CValue calcCorner(void){
  return CValue();
}
// recursive case
template<class Head, class... Tail>
CValue calcCorner(const Head& head, Tail&... tail){
  CValue res = calcCornerEach(head);
  CValue tmp = calcCorner(tail...);
  res.update(tmp);
  return res;
}

ComplexArg width, xcenter, ycenter, scale;
int realw = 500, margin = 100, totalw = realw+2*margin;

Mat createWhiteImage(){
  Mat mat = Mat::zeros(totalw,totalw,CV_8UC3);
  int cols = mat.cols;
  int rows = mat.rows;
  for (int j = 0; j < rows; j++) {
    for (int i = 0; i < cols; i++) {
      mat.at<Vec3b>(j, i)[0] = 255; //青
      mat.at<Vec3b>(j, i)[1] = 255; //緑
      mat.at<Vec3b>(j, i)[2] = 255; //赤
    }
  }
  return mat;
}

// 座標を画像用に変換
P coordinateTrans(P p){
  p.imag(-p.imag());
  p += P(-xcenter+width/2.0,ycenter+width/2.0);
  p *= scale;
  p += P(margin,margin);
  return p;
}

void addAxis(Mat &mat){
  P origin = coordinateTrans(P(0,0));
  line(mat, Point(origin.real(), 0), Point(origin.real(), totalw-1), Scalar(0,0,0));
  line(mat, Point(0, origin.imag()), Point(totalw-1, origin.imag()), Scalar(0,0,0));
}

// P case
void addElemEach(Mat &mat, const P &p){
  P after = coordinateTrans(p);
  // dump(after);
  circle(mat, Point(after.real(),after.imag()), 3, Scalar(0,0,0), -1);
}
// L case
void addElemEach(Mat &mat, const L &l){
  P startp = l[0], endp = l[1];
  startp = coordinateTrans(startp);
  endp = coordinateTrans(endp);
  line(mat, Point(startp.real(),startp.imag()), Point(endp.real(),endp.imag()), Scalar(0,0,0));
}
// G case
void addElemEach(Mat &mat, const G &g){
  int n = g.size();
  for(int i = 0; i < n; i++){
    P startp = g[i], endp = g[(i+1)%n];
    startp = coordinateTrans(startp);
    endp = coordinateTrans(endp);
    line(mat, Point(startp.real(),startp.imag()), Point(endp.real(),endp.imag()), Scalar(0,0,0));
  }
}
// vector<L> case
void addElemEach(Mat &mat, const vector<L> &ls){
  for(auto l : ls)
    addElemEach(mat,l);
}
// C case
void addElemEach(Mat &mat, const C &c){
  P afterp = coordinateTrans(c.p);
  int afterr = scale * c.r;
  circle(mat, Point(afterp.real(),afterp.imag()), afterr, Scalar(0,0,0),1);
}
// base case
void addElem(Mat &mat){
}
// recursive case
template<class Head, class... Tail>
void addElem(Mat &mat, const Head& head, Tail&... tail){
  addElemEach(mat, head);
  addElem(mat, tail...);
}

template<class Head, class... Tail>
void plot(const Head& head, Tail&... tail){
  CValue cvalue(0,0,0,0); // 原点
  cvalue.update(calcCorner(head,tail...));

  width = max(cvalue.xmax-cvalue.xmin, cvalue.ymax-cvalue.ymin);
  xcenter = (cvalue.xmin + cvalue.xmax) / 2;
  ycenter = (cvalue.ymin + cvalue.ymax) / 2;
  scale = realw / width; // 複素平面でも1が画像で幾つか

  Mat mat = createWhiteImage();
  addAxis(mat);
  addElem(mat, head, tail...);
  namedWindow("sample", WINDOW_AUTOSIZE);
  imshow("sample", mat);
  waitKey(0);
  destroyAllWindows();
  // imwrite("plot2.png",mat);
}
