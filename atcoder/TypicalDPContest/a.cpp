#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define int ll

main()
{
  int n; cin >> n;
  vi p(n); rep(i,n) cin >> p[i];
  int sum = SUM(p);
  vvi dp(n+1,vi(sum+1)); // dp[i][j] : i個の中から選んでjが作れるか
  rep(i,n+1) dp[i][0] = 1;

  rep(i,n) rep(j,sum+1){
    dp[i+1][j] = dp[i][j]; // 使わない時
    if(j >= p[i])
      dp[i+1][j] = max(dp[i][j - p[i]], dp[i+1][j]); // 使うとき
  }
    
  int ans = 0;
  rep(j,sum+1)
    rep(i,n+1)
      if(dp[i][j]){
	ans++;
	break;
      }
  /*
  rep(i,n+1){
    rep(j,sum+1) cout << dp[i][j];
    cout << endl;
  }
  */
  cout << ans << endl;
}
