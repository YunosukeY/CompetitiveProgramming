#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;
#define int ll

main(){
  int n,a; cin >> n >> a;
  vi x(n); rep(i,n) cin >> x[i];
  int dp[n+1][n+1][n*a+1];

  //rep(i,n) cout << x[i] << endl;

  rep(j,n+1){
    rep(k,n+1){
      rep(s,n*a+1){
	if(j == 0 and k == 0 and s == 0) dp[j][k][s] = 1;
	else if((j > 0) and (s < x[j-1])) dp[j][k][s] = dp[j-1][k][s];
	else if((j > 0) and (k > 0) and (x[j-1] <= s)) dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]];
	else dp[j][k][s] = 0;
	//cout << dp[j][k][s];
      }
      //cout << endl;
    }
    //cout << endl;
  }
  
  int ans = 0; FOR(i,1,n+1){
    ans += dp[n][i][i*a];
    //cout << i << " : " << dp[n][i][i*a] << endl;
  }
  cout << ans << endl;
}
