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

signed main(){
  int n, m ;cin >> n >> m;
  vi s(n); rep(i,n) cin >> s[i];
  vi t(m); rep(i,m) cin >> t[i];
  vvi dp(n+1,vi(m+1));
  rep(i,n+1) dp[i][0] = 1;
  rep(j,m+1) dp[0][j] = 1;
  rep(i,n) rep(j,m){
    dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
    if(s[i] != t[j]) dp[i+1][j+1] -= dp[i][j];
    dp[i+1][j+1] %= mod;
  }
  if(dp[n][m] < 0) dp[n][m] += mod;
  cout << dp[n][m] << endl;
}
