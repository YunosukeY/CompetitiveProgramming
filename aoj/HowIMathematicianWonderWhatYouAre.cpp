#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

// 基本要素

const double EPS = 1e-8;
const double INF = 1e12;
// 点
typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
// 外積
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
// 内積
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

// 直線
// 線分は端点を入れる
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

// 多角形
// 頂点は反時計にすること
typedef vector<P> G;

// a->b->cという折れ線がどうなっているか
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // 反時計周り
  if (cross(b, c) < 0)   return -1;       // 時計回り
  if (dot(b, c) < 0)     return +2;       // c--a--b の順に一直線
  if (norm(b) < norm(c)) return -2;       // a--b--c の順に一直線
  return 0;
}

// 直線の交点
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

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

signed main(){
  int n;
  while(cin >> n, n){
    G g(n);
    rep(i,n){
      double x, y; cin >> x >> y;
      g[i] = {x, y};
    }
    G res(4);
    res[0] = {0,0};
    res[1] = {10000,0};
    res[2] = {10000,10000};
    res[3] = {0,10000};
    rep(i,n){
      L l(g[i],g[(i+1)%n]);
      res = convex_cut(res, l);
    }
    dump(area2(res));
    if(res.size()) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
