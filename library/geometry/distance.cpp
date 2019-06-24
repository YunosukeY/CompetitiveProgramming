// 距離

// 点の線への射影
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
// 線対称な点
P reflection(const L &l, const P &p) {
  return p + 2 * (projection(l, p) - p);
}
// 直線と点
double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}
// 直線同士
double distanceLL(const L &l, const L &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
// 直線と線分
double distanceLS(const L &l, const L &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
// 線分と点
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
// 線分と線分
double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
// 点同士
double distancePP(const P &p, const P &q){
  return abs(p-q);
}
// 直線の交点
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) return P(nan(""),nan("")); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

// 円同士の交点
// 1点または2点で交わることを要求する
// 交わらない場合はnanを返す
pair<P, P> crosspointCC(const C& c1, const C& c2) {
    double d = abs(c1.p - c2.p);
    double rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
    double rs = sqrt(c1.r*c1.r - rc*rc);
    P diff = (c2.p - c1.p) / d;
    return make_pair(c1.p + diff * P(rc, rs), c1.p + diff * P(rc, -rs));
}

// 円と直線の交点
vector<P> crosspointCL(const C& c, const L& l) {
  P h = perf(l, c.p);
  double d = abs(h - c.p);
  vector<P> res;
  if(d < c.r - EPS){
    P x = l.dir / abs(l.dir) * sqrt(c.r*c.r - d*d);
    res.push_back(h + x);
    res.push_back(h - x);
  }else if(d < c.r + EPS){
    res.push_back(h);
  }
  return res;
}
