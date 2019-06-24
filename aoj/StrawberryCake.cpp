#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

const double EPS = 1e-10;
// 点
typedef complex<double> P;
// 外積
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
// 内積
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

// 直線
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

// 多角形
typedef vector<P> G;

// 入力
G g;

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // 反時計周り
  if (cross(b, c) < 0)   return -1;       // 時計回り
  if (dot(b, c) < 0)     return +2;       // c--a--b の順に一直線
  if (norm(b) < norm(c)) return -2;       // a--b--c の順に一直線
  return 0;
}

P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];
  if (abs(A) < EPS) assert(false);
  return m[0] + B / A * (m[1] - m[0]);
}

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

double area2(const G& poly) {
  double A = 0;
  for (int i = 0; i < poly.size(); ++i) 
    A += cross(poly[i], poly[(i+1)%poly.size()]);
  return A;
}

double a; // 面積の半分

// 面積が半分以下の時okとする
bool solve(double deg){
  P zero(0,0);
  P t(sin(deg),cos(deg));
  t *= 100;
  L l(zero,t);
  G f = convex_cut(g,l);
  dump(a, area2(f));
  if(area2(f) - 1e-5 < a) return true;
  else return false;
}

double bs(double _ok, double _ng){
  double ok = _ok;
  double ng = _ng;

  while(abs(ok - ng) > 1e-15){
    double mid = (ok + ng) / 2;
    if(solve(mid)){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  return ok;
}

signed main(){
  int n;
  P zero(0,0);
  while(cin >> n, n){
    g.clear(); g.resize(n);
    rep(i,n){
      double x, y; cin >> x >> y;
      g[i] = {x, y};
    }
    a = area2(g)/2;
    // dump(a);
    double ok = 0, ng = M_PI;
    if(solve(ok) == false) swap(ok, ng);
    //dump(ok,ng);
    double ans = bs(ok,ng);
    P t(sin(ans),cos(ans));
    t *= 100;
    dump("hoge");
    solve(ans);
    printf("%.15f %.15f\n",real(t),imag(t));
  }
}
