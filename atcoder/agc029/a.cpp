#include <bits/stdc++.h>
using namespace std;

#define rep(i,a) for(int i=0,i##_cond=(a);i<i##_cond;++i)

int main(){
  string s; cin >> s;
  long long c = 0, ans = 0;
  rep(i,s.size()){
    if(s[i] == 'B') c++;
    else ans += c;
  }
  cout << ans << endl;
}
