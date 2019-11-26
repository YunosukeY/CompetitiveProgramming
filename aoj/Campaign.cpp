#include <bits/stdc++.h>
using namespace std;

// #include "../dump.hpp"
// #include "../dump/plot.hpp"

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

const double EPS = 1e-8;
using P =  complex<double>;
namespace std{
  bool operator <(const P &a, const P &b){ // 辞書順
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
  bool operator ==(const P &a, const P &b){
    return abs(a-b) < EPS;
  }
  bool isnan(const P&p){
    return isnan(p.real()) or isnan(p.imag());
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
using G = vector<P>;

P crosspoint(const L &l, const L &m){
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];
  if (abs(A) < EPS) return P(nan(""),nan(""));
  return m[0] + B / A * (m[1] - m[0]);
}

int ccw(P a, P b, P c){
  b -= a; c -= a;
  if(cross(b, c) > 0)   return +1;       // 反時計周り
  if(cross(b, c) < 0)   return -1;       // 時計回り
  if(dot(b, c) < 0)     return +2;       // c--a--b の順に一直線
  if(norm(b) < norm(c)) return -2;       // a--b--c の順に一直線, a==bも含む
  return 0;                              // a--c--b の順に一直線, b==cも含む
}

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
bool intersectSS(const L &s, const L &t) {
  if(ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
     ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0) return true;
  // 端点が乗っている場合
  if(intersectSP(s,t[0]) or intersectSP(s,t[1]) or
     intersectSP(t,s[0]) or intersectSP(t,s[1])) return true;
  return false;
}
bool intersectGS(const G &g, const L &s){
  vector<P> ps;
  int n = g.size();
  rep(i, n){
    L tmps(g[i], g[(i+1)%n]);
    if(intersectSS(tmps, s)){
      P tmpp = crosspoint(tmps, s);
      if(not isnan(tmpp))
	ps.push_back(tmpp);
    }
  }
  sort(all(ps));
  ps.erase(unique(all(ps)), ps.end());
  if(ps.size() >= 2) return true;
  else return false; // 接する場合もNO 
}

bool gp_contains(const G& g, const P& p){
  double sum = 0.0;
  int n = g.size();
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;
    if(intersectSP(L(g[i], g[j]-g[i]), p))
      return true;
    sum += arg((g[j]-p)/(g[i]-p));
  }
  return (abs(sum) > 1);
}

int main(){
  // input
  int n, m; cin >> n >> m;
  vector<G> gs(n);
  rep(i,n){
    int l; cin >> l;
    rep(j,l){
      double x, y; cin >> x >> y;
      gs[i].push_back(P(x,y));
    }
  }
  vector<P> ps(m);
  rep(i,m){
    double x, y; cin >> x >> y;
    ps[i] = P(x,y);
  }

  // 候補を列挙
  vector<vector<L>> canl(m);
  rep(i,m)
    for(auto g : gs)
      for(auto gp : g)
	canl[i].push_back(L(ps[i],gp));
  vector<P> canp;
  rep(i,m) FOR(j,i+1,m){
    for(auto l1 : canl[i])
      for(auto l2 : canl[j]){
	P tmp = crosspoint(l1, l2);
	if(isnan(tmp)) continue;
	bool f = true;
	for(auto g : gs) if(gp_contains(g, tmp)) f = false;
	if(f) canp.push_back(tmp);
      }
  }
  
  // 候補を確認
  int ans = 1;
  for(auto can : canp){
    int tmp = 0;
    for(auto p : ps){
      L tmpl(can, p);
      bool f = true;
      for(auto g : gs)
	if(intersectGS(g, tmpl)) f = false;
      if(f){
	tmp++;
      }
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
}
