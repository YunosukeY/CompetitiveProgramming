// 凸多角形の切断
// 直線の左側を残す
// 凸出ない場合は?

// !CAUTION! number は有理数以上
G convex_cut(const G& Poly, const L& l) {
  G Q;
  for (int i = 0; i < Poly.size(); ++i) {
    P A = Poly[i], B = Poly[(i+1)%Poly.size()];
    if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
    if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
      Q.push_back(crosspoint(L(A, B), l));
  }
  return Q;
}
