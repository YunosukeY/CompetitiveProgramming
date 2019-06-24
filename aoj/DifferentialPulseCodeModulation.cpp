#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr ll inf = 1ll<<30;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

signed main(){
  int n, m;
  while(cin >> n >> m, n){
    vi c(m); rep(i,m) cin >> c[i];
    vi x(n); rep(i,n) cin >> x[i];
    vvi dp(n+1, vi(256,inf)); // dp[i][j] : yi番目がjの時の最小コスト
    dp[0][128] = 0;
    rep(i,n) rep(j,256) rep(k,m){ // dp[i][j]からc[k]を使った時
      int next = j + c[k];
      if(next < 0) next = 0;
      else if(255 < next) next = 255;
      chmin(dp[i+1][next], dp[i][j] + (x[i] - next)*(x[i]-next));
    }
    cout << *min_element(all(dp[n])) << endl;
  }
}
