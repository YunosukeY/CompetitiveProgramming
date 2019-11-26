#include <bits/stdc++.h>
using namespace std;


#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;
constexpr ll mod = 1e9+7;

signed main(){
  string s; cin >> s;

  vi dp(13);
  dp[0] = 1;
  for(auto c : s){
    vi next(13);
    if(isdigit(c)){
      int x = c - '0';
      rep(i,13) next[(i*10+x)%13] += dp[i];
      rep(i,13) next[i] %= mod;
    }else{
      rep(x,10){
	rep(i,13) next[(i*10+x)%13] += dp[i];
	rep(i,13) next[i] %= mod;
      }
    }
    dp = next;
  }
  cout << dp[5] << endl;
}
