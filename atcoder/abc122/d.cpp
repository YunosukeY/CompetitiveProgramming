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
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

signed main(){
  int n; cin >> n;
  vvi dp(n+1,vi(4)); // dp[i][j]:i文字目がjである違反しない文字列の数
  // 0:A, 1:T, 2:G, 3:C
  rep(j,4) dp[0][j] = 1;
  rep(i,n){
    int tmptotal = 0;
    rep(j,4){
      tmptotal += dp[i][j];
      tmptotal %= mod;
    }
    rep(j,4) dp[i+1][j] = tmptotal;
    
    if(i >= 3){ // AGC, GAC, ACGの分を引く
      int agc = (dp[i-1][0] * dp[i][2]) % mod;
      dp[i+1][3] -= agc;
      dp[i+1][3] %= mod;
      int gac = (dp[i-1][2] * dp[i][0]) % mod;
      dp[i+1][3] -= gac;
      dp[i+1][3] %= mod;
      int acg = (dp[i-1][0] * dp[i][3]) % mod;
      dp[i+1][2] -= acg;
      dp[i+1][2] %= mod;
    }
    if(i >= 4){ // A*GC, AG*Cの分を引く
      int a_gc = 0; // atgc, aggc, acgc;
      a_gc += (((dp[i-1][1] * dp[i-1][2]) % mod) * dp[i-1][3]) % mod;
      a_gc *= (dp[i-2][0] * dp[i][2]) % mod;
      a_gc %= mod;
      dp[i+1][3] -= a_gc;
      dp[i+1][3] %= mod;
      int agtc = (((dp[i-2][0] * dp[i-1][2]) % mod) * dp[i][1]) % mod;
      dp[i+1][3] -= agtc;
      dp[i+1][3] %= mod;
    }
  }
  dump(dp);
  int ans = 0;
  rep(j,4){
    ans += dp[n][j];
    ans %= mod;
  }
  if(ans < 0) ans += mod;
  cout << ans << endl;
}
