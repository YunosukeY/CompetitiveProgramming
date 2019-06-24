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
#define pb push_back
#define w first
#define v second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

constexpr int inf = 1ll<<60;

main(){
  int N,W,C; cin >> N >> W >> C;

  vector<vector<pii>> a(50);
  rep(i,N){
    int x,y,z;
    cin >> x >> y >> z;
    a[z-1].pb(pii(x,y));
  }

  // dp[i][k] : 色iのみで重さkでできる価値の最大値
  vvi cdp(50);
  rep(i,50){
    // tmpdp[j+1][k] : 色iの初めのj個で重さkでできる価値の最大値
    vvi tmpdp(a[i].size()+1,vi(W+1,-inf));
    tmpdp[0][0] = 0;
    
    rep(j,a[i].size()) rep(k,W+1){
      // 使わない
      tmpdp[j+1][k] = max(tmpdp[j+1][k], tmpdp[j][k]);

      // 使う
      if(k + a[i][j].w <= W)
	tmpdp[j+1][k+a[i][j].w] = max(tmpdp[j+1][k], tmpdp[j][k]+a[i][j].v);
    }
    dump(tmpdp);
    cdp[i] = move(tmpdp[a[i].size()]);
  }
  // dump(cdp);

  // dp[i+1][j][k] : 初めのi色で重さj,色数kでできる価値の最大値
  vector<vvi> dp(51,vvi(W+1,vi(C+1,-inf)));
  dp[0][0][0] = 0;
  rep(i,50) rep(j,W+1) rep(k,C+1){
    // 使わない
    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

    // i色目を使う
    if(k != C){
      rep(l,cdp[i].size())
	if(j + l <= W)
	  dp[i+1][j+l][k] = max(dp[i+1][j][k], dp[i][j][k]+cdp[i][l]);
    }
  }
  dump(dp);
  
}
