#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
typedef long long ll;

ll dp[20][2][2];

main(){
  string a,b; cin >> a >> b;
  a = to_string(stoll(a) - 1);
  
  int n = b.size();
  memset(dp,0,20*2*2*sizeof(ll));
  dp[0][0][0] = 1;
  rep(i,n) rep(j,2) rep(k,2){
    int lim = j ? 9 : b[i] - '0';
    rep(d, lim + 1){
      dp[i + 1][j or d < lim][k or d == 4 or d == 9] += dp[i][j][k];
    }
  }
  ll ans= 0;
  rep(j,2) ans += dp[n][j][1];
  //cout << ans << endl;

  n = a.size();
  memset(dp,0,20*2*2*sizeof(ll));
  dp[0][0][0] = 1;
  rep(i,n) rep(j,2) rep(k,2){
    int lim = j ? 9 : a[i] - '0';
    rep(d, lim + 1){
      dp[i + 1][j or d < lim][k or d == 4 or d == 9] += dp[i][j][k];
    }
  }
  rep(j,2) ans -= dp[n][j][1];

  cout << ans << endl;
}
