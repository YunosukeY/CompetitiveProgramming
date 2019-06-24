#include<bits/stdc++.h>
1;4205;0cusing namespace std;
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

int main(){
  int n;
  while(cin >> n, n){
    vector<int> w(n); rep(i,n) cin >> w[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1));

    // 区間DP
    FOR(j,2,n+1){ // 区間長
      for(int i = 0; i+j <= n; ++i){ // 区間左端 dp[i][i+j]を決定する
	//printf("[%d,%d)\n",i,i+j);
	FOR(k,2,j-1) // dp[i][i+k],dp[i+k][i+j]を元に計算
	  dp[i][i+j] = max(dp[i][i+j], dp[i][i+k]+dp[i+k][i+j]);
	
	if(abs(w[i] - w[i+j-1]) <= 1 and (i+1==j or dp[i+1][i+j-1]==j-2))
	  dp[i][i+j] = max(dp[i][i+j], j);
      }
    }
    
    cout << dp[0][n] << endl;
  }
}
