#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using pii = pair<int,int>;
constexpr int inf = 1ll<<30;

int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;

  vector<pii> pos; // 1が連続する半開区間[l,r)を格納
  int l, r; l = r = 0;
  while(r < n and s[r] == '1') r++;
  pos.emplace_back(l,r);
  l = r = 0;
  while(1){
    while(l < n and s[l] == '1') l++;
    while(l < n and s[l] == '0') l++;
    r = l;
    while(r < n and s[r] == '1') r++;
    pos.emplace_back(l,r);
    if(r >= n) break;
  }
  
  int ans = -inf;
  rep(i,pos.size()-k) ans = max(ans, pos[i+k].second - pos[i].first);
  if(k >= pos.size()) ans = max(ans, pos.back().second - pos.front().first);
  cout << ans << endl;
}
