using P = valarray<double>;
const int dim = 3;

double dot(const P& a, const P& b){
  return (a * b).sum();
}
P cross(const P& a, const P& b){
  return a.cshift(+1)*b.cshift(-1)
    - a.cshift(-1)*b.cshift(+1);
}
double dist(const P& a, const P& b){
  return dot(a-b, a-b);
}
double norm(const P&p){
  return dot(p,p);
}
double absP(const P& p){
  return sqrt(norm(p));
}

double ll_distance(L& a, L& b) {
  P pa = a[0];
  P pb = b[0];
  P da = a[1] - a[0];
  P db = b[1] - b[0];
  double num = dot( (db * dot(da, db) - da * dot(db, db)) , pb - pa );
  double denom = dot(da, db) * dot(da, db) - dot(da, da) * dot(db, db);
  double ta;
  if (abs(denom) < EPS)
    ta = 0;
  else
    ta = num / denom;
  P p = pa + da * ta;
  return lp_distance(b, p);
}
