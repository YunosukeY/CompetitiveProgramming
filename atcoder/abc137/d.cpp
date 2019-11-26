#include <bits/stdc++.h>
using namespace std;


#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;

signed main(){
  int n, m; cin >> n >> m;

  vvi d(m);
  rep(i,n){
    int a, b; cin >> a >> b;
    if(m - a >= 0)
      d[m-a].push_back(b);
  }
  priority_queue<int> q;
  int ans = 0;
  ROF(i,m,0){
    for(auto a : d[i])
      q.push(a);
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}
