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
  int n,m; cin >> n >> m;
  vi a(n); rep(i,n) cin >> a[i];
  vi b(m); rep(i,m) cin >> b[i];

  vvi dp(n+1,vi(m+1)); //dp[i+1][j+1] : Aからi個、Bからj個取った時の最大値
  ROF(i,n+1,0) ROF(j,m+1,0){
    if(i == n and j == m) continue;
    
    if((i + j) % 2 == 0){ // 自分
      if(i < n) dp[i][j] = max(dp[i][j], dp[i+1][j] + a[i]);
      if(j < m) dp[i][j] = max(dp[i][j], dp[i][j+1] + b[j]);
    }else{ // 敵
      dp[i][j] = inf;
      if(i < n) dp[i][j] = min(dp[i][j], dp[i+1][j]);
      if(j < m) dp[i][j] = min(dp[i][j], dp[i][j+1]);
    }
  }
  dump(dp);
  cout << dp[0][0] << endl;
}
