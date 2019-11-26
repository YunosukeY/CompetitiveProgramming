#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vs = vector<string>;
constexpr int inf = 1<<30;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

string replace(string s, const string &a, const string &b){
  string::size_type pos = 0;
  while(1){
    pos = s.find(a,pos);
    if(pos == string::npos) break;
    s.replace(pos,a.size(),b);
    pos += b.size();
  }
  return s;
}

int bfs(const vs &as, const vs &bs, string c, const string &d, int depth){
  int n = as.size();
  int minv = inf;
  int csz = c.size(), dsz = d.size();
  rep(i,n){
    string after = replace(c, as[i], bs[i]);
    if(after.size() == csz) continue;
    if(after.size() < dsz) chmin(minv, bfs(as, bs, after, d, depth+1));
    else if(after == d) chmin(minv, depth);
  }
  return minv;
}

signed main(){
  int n;
  while(cin >> n, n){
    vs as(n), bs(n);
    rep(i,n) cin >> as[i] >> bs[i];
    string c, d; cin >> c >> d;
    int ans = bfs(as,bs,c,d,1);
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
  }
}
