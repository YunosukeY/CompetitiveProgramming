#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
 
const double EPS = 1e-8;
using P = valarray<double>;
const int dim = 3;
using L = vector<P>;
struct C{
  P p; double r;
};
 
double dot(const P& a, const P& b){
  return (a * b).sum();
}
double norm(const P& p){
  return dot(p, p);
}
double absP(const P& p){
  return sqrt(norm(p));
}
bool intersectSP(const L &s, const P &p) {
  return absP(s[0]-p)+absP(s[1]-p)-absP(s[1]-s[0]) < EPS;
}
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
double distanceSP(const L &s, const P &p) {
  const P r(projection(s, p));
  if (intersectSP(s, r)) return absP(r - p);
  return min(absP(s[0] - p), absP(s[1] - p));
}

int main(){
  int n, q; cin >> n >> q;
  vector<C> cs(n);
  vector<long long> cost(n);
  rep(i,n){
    cs[i].p.resize(3);
    rep(j,3) cin >> cs[i].p[j];
    cin >> cs[i].r;
    cin >> cost[i];
  }
  vector<L> ls(q, L(2, P(3)));
  rep(i,q){
    rep(j,3) cin >> ls[i][0][j];
    rep(j,3) cin >> ls[i][1][j];
  }
   
  rep(i,q){
    long long res = 0;
    rep(j,n){
      if(distanceSP(ls[i],cs[j].p) - EPS < cs[j].r) res += cost[j];
    }
    cout << res << endl;
  }
}
