#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr ll MOD = 1e9+7;
template<class T>T mod(T a){return a%MOD;}
template<class T>void add(T &a, const T &b){a += b; a %= MOD;}

signed main(){
  int h,w,k; cin >> h >> w >> k;

  vi c = {1,2,3,5,8,13,21,34,55};

  vvi dp(h+1,vi(w));
  dp[0][0] = 1;
  rep(hi,h){
    rep(wi,w){
      if(wi-1 >= 0)
	add(dp[hi+1][wi-1], mod(c[max(0ll,wi-2)] * c[max(0ll,w-wi-2)] * dp[hi][wi]));
      
      add(dp[hi+1][wi], mod(c[max(0ll,wi-1)] * c[max(0ll,w-wi-2)] * dp[hi][wi]));

      if(wi+1 < w)
	add(dp[hi+1][wi+1], mod(c[max(0ll,wi-1)] * c[max(0ll,w-wi-3)] * dp[hi][wi]));
    }
  }
  dump(dp)

  cout << dp[h][k-1] << endl;
}
