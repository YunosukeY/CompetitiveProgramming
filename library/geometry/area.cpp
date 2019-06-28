// 凸多角形の面積の2倍
double area(const G& g) {
  int n = g.size();
  double s = 0.0;
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;
    s += cross(g[i], g[j])/2;
  }
  return abs(s);
}

// 2円の共通部分の面積
double cc_area(const C& c1, const C& c2){
  double d = abs(c1.p - c2.p);
  if(c1.r + c2.r <= d + EPS){
    return 0.0;
  }else if(d <= abs(c1.r - c2.r) + EPS){
    double r = c1.r <? c2.r;
    return r * r * PI;
  }else{
    double rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
    double theta = acos(rc / c1.r);
    double phi = acos((d - rc) / c2.r);
    return c1.r*c1.r*theta + c2.r*c2.r*phi - d*c1.r*sin(theta);
  }
}
