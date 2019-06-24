#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
constexpr int mod = 1e9 + 7;

int main() {
  int d; cin >> d;
  string s; cin >> s;
  int n = s.length();

  // dp[i+1][j][k] : 上からi桁目決めた時,余りがk
  vector<vector<vector<int>>> dp(n+10,vector<vector<int>>(2,vector<int>(d)));
  dp[0][0][0] = 1;
  rep(i,n) rep(j,2) rep(k,d){
    int lim = j ? 9 : s[i] - '0'; // lim未満なら以降大丈夫
    rep(a, lim+1) // 次の桁の数がa
      (dp[i+1][j || a<lim][(k+a)%d] += dp[i][j][k]) %= mod;
  }

  int ans = 0;
  rep(j,2)
    (ans += dp[n][j][0]) %= mod;
  cout << ans-1 << endl;
}
