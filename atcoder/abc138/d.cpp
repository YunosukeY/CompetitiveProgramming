#include <bits/stdc++.h>
using namespace std;


#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;

vvi g;
vi ans;
vi d;
vi x;

void dfs(int s){ // sを根としてdfs
  stack<int> st;
  d[s] = 1;
  st.push(s);
  
  while(!st.empty()){
    int next = st.top();
    st.pop();
    ans[next] += x[next];
    
    rep(i, g[next].size()){
      int c = g[next][i];
      
      if(d[c] == 0){
	d[c] = 1;
	ans[c] = ans[next];
	st.push(c);
      }
    }
  }
}

signed main(){
  int n, q; cin >> n >> q;
  g.resize(n);
  rep(i,n-1){
    int a, b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  x.resize(n);
  rep(i,q){
    int a, b; cin >> a >> b; a--;
    x[a] += b;
  }

  ans.resize(n);
  d.resize(n);
  dfs(0);

  cout << ans[0];
  FOR(i,1,n) cout << " " << ans[i];
  cout << endl;
}
