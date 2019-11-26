#include <bits/stdc++.h>
using namespace std;

using vi  = vector<int>;
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

signed main(){
  string s; cin >> s;
  int l, m, r;
  l = m = r = 0;
  vi ans(s.size());
  while(1){
    while(s.substr(m,2) != "RL") m++;
    r = m;
    while(r < s.size()-1 and s.substr(r,2) != "LR") r++;
    ans[m] += (r-l+1)/2;
    ans[m+1] += (r-l+1)/2;
    if((r-l+1)%2==1) ans[m + ((m-l)&1)]++;
    
    if(r == s.size()-1) break;
    l = m = r+1;
  }
  cout << ans[0];
  FOR(i,1,s.size()) cout << " " << ans[i];
}
