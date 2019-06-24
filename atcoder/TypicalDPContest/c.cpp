#include<bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;

double pro(int r, int s){
  return 1/(1+pow(10,double(s-r)/400));
}

main(){
  int k; cin >> k;
  vi r(pow(2,k)); rep(i,pow(2,k)) cin >> r[i];

  vector<vector<double>> dp(r.size(),vector<double>(k+1)); // dp[i][j+1] : i人目がj試合目で勝つ確率
  rep(i,r.size()) dp[i][0] = 1; // 初めは確率1

  rep(j,k) rep(i,r.size()){
    int l = pow(2,j);
    int s = (i^l)&~(l-1);
    FOR(p,s,s+l){ // p人目と対戦
      //dump(i,p);
      dp[i][j+1] += dp[p][j] * pro(r[i],r[p]);
    }
    dp[i][j+1] *= dp[i][j];
  }
  //dump(dp);
  rep(i,r.size()) printf("%.10f\n",dp[i][k]);
}
