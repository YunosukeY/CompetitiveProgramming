#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
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

const double EPS = 1e-8;

signed main(){
  int n, d; cin >> n >> d;
  vvi x(n,vi(d));
  rep(i,n) rep(j,d) cin >> x[i][j];
  int ans = 0;
  rep(i,n) FOR(j,i+1,n){
    int tmp = 0;
    rep(k,d) tmp += (x[i][k]-x[j][k]) * (x[i][k]-x[j][k]);
    int s = sqrt(tmp);
    if(s * s == tmp) ans++;
  }
  cout << ans << endl;
}
