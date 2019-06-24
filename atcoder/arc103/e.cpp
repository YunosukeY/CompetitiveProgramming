#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)

main(){
  string s; cin >> s;
  int n = s.size();

  bool f = false;
  if(s[0] == '0' or s[n-1] == '1') f = true;
  rep(i,n/2)
    if(s[i] != s[n-i-2]) f = true;
  if(f){
    cout << -1 << endl;
    return 0;
  }

  int k = n;
  ROF(i,n-1,0){
    cout << i+1 << " " << k << endl;
    if(s[i] == '1') k = i + 1;
  }
}
