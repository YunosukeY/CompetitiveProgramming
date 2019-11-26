#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

const double EPS = 1e-8;
using P =  complex<double>;
namespace std {
  bool isnan(const P&p){
    return isnan(p.real()) or isnan(p.imag());
  }
}
struct C {
  P p; double r;
  C(const P &p_, double r_) : p(p_), r(r_) { }
};

// 交わらない場合はnanを返す
pair<P, P> crosspointCC(const C& c1, const C& c2){
  double d = abs(c1.p - c2.p);
  double rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
  double rs = sqrt(c1.r*c1.r - rc*rc);
  P diff = (c2.p - c1.p) / d;
  return make_pair(c1.p + diff * P(rc, rs), c1.p + diff * P(rc, -rs));
}

signed main(){
  int n;
  while(cin >> n, n){
    vector<P> ps(n);
    rep(i,n){
      double x, y; cin >> x >> y;
      ps[i].real(x);
      ps[i].imag(y);
    }
    vector<P> can;
    rep(i,n) FOR(j,i+1,n){
      C c1(ps[i],1), c2(ps[j],1);
      auto tmp = crosspointCC(c1, c2);
      if(not isnan(tmp.first))
	can.push_back(tmp.first);
      if((not isnan(tmp.second)) and abs(tmp.first - tmp.second) > EPS)
	can.push_back(tmp.second);
    }

    int ans = 1;
    rep(i,can.size()){
      int tmp = 0;
      rep(j,n)
	if(abs(can[i] - ps[j]) - EPS < 1) tmp++;
      chmax(ans, tmp);
    }
    cout << ans << endl;
  }
}
