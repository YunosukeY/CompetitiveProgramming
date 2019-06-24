#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
constexpr int inf = 1<<30;

signed main(){
  string s; cin >> s;
  int ans = inf;
  rep(i,2){ // 初めの色をiにする
    int tmp = 0;
    rep(j,s.size()){
      if(j % 2 == 0 and s[j]-'0' != i) tmp++;
      else if(j % 2 == 1 and s[j]-'0' != (i^1)) tmp++;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
