#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
typedef long long ll;

int main(){
#define int ll
  string s; cin >> s;
  int k; cin >> k; k--;
  int pos;
  rep(i,s.size()) if(s[i] != '1'){
    pos = i;
    break;
  }
  //cout << pos << endl;
  if(k < pos) cout << 1 << endl;
  else cout << s[pos] << endl;
}
