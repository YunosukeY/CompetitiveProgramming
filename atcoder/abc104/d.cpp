#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
constexpr ll mod = 1e9+7;

void add(ll &a, ll b){
  a += b;
  a %= mod;
}

int main(){
#define int ll
  string s; cin >> s;
  
  vvi dp(s.size()+1,vi(4));
  dp[0][0] = 1;
  rep(i,s.size()){
    if(s[i] == '?')
      rep(j,4) add(dp[i+1][j], dp[i][j]*3);
    else
      rep(j,4) add(dp[i+1][j], dp[i][j]);

    if(s[i] == 'A' or s[i] == '?')
      add(dp[i+1][1],dp[i][0]);
    if(s[i] == 'B' or s[i] == '?')
      add(dp[i+1][2],dp[i][1]);
    if(s[i] == 'C' or s[i] == '?')
      add(dp[i+1][3],dp[i][2]);
  }
  cout << dp[s.size()][3] << endl;
}
