#include<bits/stdc++.h>
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

constexpr int inf = 1ll<<62;
constexpr int mod = 1e9+7;

main(){
  int n,k; scanf("%lld%lld",&n,&k);
  vi a(n); rep(i,n) scanf("%lld",&a[i]);

  vi b(n); // 2で何回割れるか
  rep(i,n)
    while(a[i]){
      b[i]++;
      a[i] /= 2;
    }
  dump(b);

  vvi dp(n+1,vi(k+1)); // dp[i][j] : 初めのi個でj回操作をするときの個数
  rep(i,n+1) dp[i][0] = 1;

  rep(i,n) rep(j,k){
    dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
    dp[i+1][j+1] %= mod;
  }
  dump(dp);
  cout << dp[n][k] << endl;
}
