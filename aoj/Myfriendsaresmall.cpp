/*
  普通にナップザックをすると極大かどうかの検査ができない
  使わないものを決めれば検査できる？
  小さいものを使わないとしてやるとよさそう
  2番目以降のものを使わない時はそれより軽いものを全部使うとすべて網羅できそう
 */


#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr ll mod = 1e9+7;
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

signed main(){
  int n, w; cin >> n >> w;
  vi ws(n); rep(i,n) cin >> ws[i];
  sort(all(ws));
  int ans = 0;
  rep(i,n){ // [0,i)を使いiを使わない場合
    vvi dp(n+1,vi(w+1,0)); // dp[i][j] : i-1個目まででjになる場合の数
    int tmp = accumulate(ws.begin(),ws.begin()+i,0);
    if(tmp > w) break;
    dp[i+1][tmp] = 1;
    FOR(j,i+1,n) FOR(k,tmp,w+1){
      add(dp[j+1][k], dp[j][k]);
      if(k + ws[j] <= w){
	add(dp[j+1][k+ws[j]], dp[j][k]);
      }
    }
    FOR(k,max(tmp,w+1-ws[i]),w+1){
      add(ans, dp[n][k]);
    }
  }
  if(accumulate(all(ws),0) <= w) ans++;
  cout << ans << endl;
}
