#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

int main(){
  int n; cin >> n;

  map<int,int> mp;
  FOR(j,2,n+1){
    int k = j;
    FOR(i,2,sqrt(j)+1){
      while(k%i == 0){
	mp[i]++;
	k /= i;
      }
    }
    if(k != 1) mp[k]++;
  }
  dump(mp);

  int res = 0;
  int a, b;
  a = b = 0;
  for(auto x : mp){
    if(2 <= x.second) a++;
    if(4 <= x.second) b++;
  }
  dump(a,b);
  res += b*(b-1)*(a-2)/2;

  a = b = 0;
  for(auto x : mp){
    if(4 <= x.second) a++;
    if(14 <= x.second) b++;
  }
  res += b*(a-1);
  
  a = b = 0;
  for(auto x : mp){
    if(2 <= x.second) a++;
    if(24 <= x.second) b++;
  }
  res += b*(a-1);

  a = 0;
  for(auto x : mp){
    if(74 <= x.second) a++;
  }
  res += a;

  cout << res << endl;
}
