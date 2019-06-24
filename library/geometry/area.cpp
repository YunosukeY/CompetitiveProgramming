double area2(const G& poly) {
  double A = 0;
  for (int i = 0; i < poly.size(); ++i) 
    A += cross(poly[i], poly[(i+1)%poly.size()]);
  return A;
}
