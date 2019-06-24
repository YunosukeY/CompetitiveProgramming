#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
using ll  = long long;

signed main(){
  int n; cin >> n;

  string s = "0000000355";
  int ans = 0;
  while(1){
    // インクリメント
    ROF(i,s.size(),0){
      if(s[i] == '7') s[i] = '3';
      else{
	if(s[i] == '5') s[i] = '7';
	else if(s[i] == '3') s[i] = '5';
	else if(s[i] == '0') s[i] = '3';
	else assert(false);
	break;
      }
    }
    if(stoll(s) > n) break;

    bool a, b, c; a = b = c = false;
    ROF(i,s.size(),0){
      if(s[i] == '3') a = true;
      else if(s[i] == '5') b = true;
      else if(s[i] == '7') c = true;
      else if(s[i] == '0') break;
      else assert(false);
    }
    if(a and b and c) ans++;
  }
  cout << ans << endl;
}
