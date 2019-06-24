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
vector<P> ps;
vector<int> v;

// 点同士
double distancePP(const P &p, const P &q){
  return sqrt(pow(real(p)-real(q),2)+pow(imag(p)-imag(q),2));
}

#define maxLoop 100

double f(double x, double y){
  int n = ps.size();
  double res = -INF;
  P now(x,y);
  rep(i,n){
    chmax(res,distancePP(now, ps[i])/v[i]);
  }
  return -res;
} // 最大値を求めたい上に凸な関数

double ysearch(double x){
  double left = 0, right = 100;
  for (ll loop = 0; loop < maxLoop; ++loop){
    if (f(x, (left*2+right)/3) > f(x, (left+right*2)/3)){
      right = (left + right * 2) / 3;
    } else {
      left = (left * 2 + right) / 3;
    }
  }
  return f(x, (right + left) * 0.5);
}

double xsearch(){
  double left = 0, right = 100;
  for (ll loop = 0; loop < maxLoop; ++loop){
    if (ysearch((left * 2 + right) / 3) > ysearch((left + right * 2) / 3)){
      right = (left + right * 2) / 3;
    } else {
      left = (left * 2 + right) / 3;
    }
  }
  return ysearch((right + left) * 0.5);
}


signed main(){
  int n;
  while(cin >> n, n){
    ps.clear(); ps.resize(n);
    v.clear();  v.resize(n);
    rep(i,n){
      double x, y; cin >> x >> y;
      ps[i] = {x, y};
      cin >> v[i];
    }
    printf("%.10lf\n",-xsearch());
  }
}
