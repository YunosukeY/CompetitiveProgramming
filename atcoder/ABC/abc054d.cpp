#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  int n,ma,mb; cin >> n >> ma >> mb;
  vi a(n),b(n),c(n); rep(i,n) cin >> a[i] >> b[i] >> c[i];

  vector<vvi> dp(n+1, vvi(n*10+1, vi(n*10+1,1<<29) ) );
  dp[0][0][0] = 0;
  rep(i,n) rep(j,n*10+1) rep(k,n*10+1){
    dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
    if(j+a[i] <= n*10 and k+b[i]<=n*10)
      dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
  }

  showvv(dp);
  
  int ans = 1 << 29;
  FOR(i,1,n*10+1) FOR(j,1,n*10+1)
    if(i * mb == j * ma) ans = min(ans, dp[n][i][j]);

  if(ans == 1<<29) cout << "-1\n";
  else cout << ans << endl;
}
