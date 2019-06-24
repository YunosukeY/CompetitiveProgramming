#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;
constexpr int mod = 1e9+7;

main(){
  int n; cin >> n;
  vi p(n+1);
  p[0] = 1;
  FOR(i,1,n+1){
    int j = 2; // 2,3,4,5,...
    while(1){
      int k = j/2 * pow(-1,j&1); // 1,-1,2,-2,3,-3,...
      int l = k * (3*k-1) / 2; // 五角数
      if(i-l < 0) break;
      p[i] += p[i-l] * pow(-1, j/2+1&1); // +,+,-,-,+,+,-,-,...
      p[i] %= mod;
      j++;
    }
    if(p[i] < 0) p[i] += mod;
  }
  dump(p);      
}
