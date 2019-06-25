// 凸多角形の面積の2倍
double area2(const G& poly){
  double A = 0;
  for(int i = 0; i < poly.size(); ++i) 
    A += cross(poly[i], poly[(i+1)%poly.size()]);
  return A;
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
