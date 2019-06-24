// 交差判定

// 直線同士
bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
         abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
// 直線と線分
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
         cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
// 直線と点
bool intersectLP(const L &l, const P &p) {
  return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
// 線分同士
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
// 線分と点
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

// 円同士
// crosspointCCで代用可能
bool intersectCC(const C &a, const C &b){
  double d = distancePP(a.p, b.p);
  if(d < a.r + EPS){ // b.pがaの内側
    return max(a.r,b.r) - (d + min(a.r,b.r)) + EPS > 0;
  }else{
    return (a.r + b.r) - EPS < d;
  }
}

// 円と直線
bool intersectCL(const C &c, const L &l){
  return distanceLP(l, c.p) - EPS < c.r;
}

// 円と点
bool intersectCP(const C &c, const P &p){
  return abs(distancePP(c.p, p) - c.r) < EPS;
}
