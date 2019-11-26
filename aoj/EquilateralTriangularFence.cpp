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
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
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

using P = complex<double>;

signed main(){
  int n;
  while(cin >> n, n){
    int k; cin >> k;
    vector<P> ps(n);
    rep(i,n){
      double x, y; cin >> x >> y;
      ps[i] = P(x,y);
    }
    auto f1 = [&](const P &p, const P &q){
      return p.imag() < q.imag();
    };
    auto f2 = [&](const P &p, const P &q){
      double tmpa = p.imag() + sqrt(3) * p.real();
      double tmpb = q.imag() + sqrt(3) * q.real();
      return tmpa < tmpb;
    };
    auto f3 = [&](const P &p, const P &q){
      double tmpa = p.imag() - sqrt(3) * p.real();
      double tmpb = q.imag() - sqrt(3) * q.real();
      return tmpa < tmpb;
    };
    vector<P> low(ps), left(ps), right(ps);
    sort(all(low),f1);
    sort(all(left),f2);
    sort(all(right),f3);

    rep(i,k+1){
      
    }
  }
}
