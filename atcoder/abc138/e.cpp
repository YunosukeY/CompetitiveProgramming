#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i) // ROF(i,n,0)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr ll inf = 1ll<<61;

signed main(){
  string s, t;
  cin >> s >> t;
  rep(i,s.size()) s[i] -= 'a';
  rep(i,t.size()) t[i] -= 'a';

  vvi table(s.size()*3,vi(26,inf));
  ROF(i,2*s.size(),0){
    table[i] = table[i+1];
    table[i][s[i%s.size()]] = i+1;
  }

  int ans = 0;
  int pos = 0;
  rep(i,t.size()){
    if(table[pos][t[i]] == inf){
      cout << -1 << endl;
      return 0;
    }
    ans += table[pos][t[i]] - pos;
    pos = table[pos][t[i]] % s.size();
  }
  cout << ans << endl;
}
