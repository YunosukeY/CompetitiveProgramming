// 直線lを垂線右方向にdis移動
L slideL(L l, double dis){
  double deg = arg(l[1]-l[0]);
  P p(dis*sin(deg),-dis*cos(deg));
  l[0] += p;
  l[1] += p;
  return l;
}
