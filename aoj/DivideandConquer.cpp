#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;

int n, m;
vvi g;
vi color; // 0:未彩色、1,-1:彩色済み

int dfs(int s){ // sを根としてdfs
  stack<int> st;
  color[s] = 1;
  st.push(s);
  
  while(!st.empty()){
    int now = st.top();
    st.pop();
    
    rep(i, g[now].size()){
      int next = g[now][i];

      if(color[next]){
	if(color[now] != color[next]) continue;
	else return next;
      }
      
      color[next] = -color[now];
      st.push(next);
    }
  }
  return -1;
}

int paintable(){
  rep(i,n)
    if(color[i] == 0){
      int res = dfs(i);
      if(res != -1) return res;
    }
  return -1;
}

signed main(){
  while(cin >> n >> m, n){
    g.clear();
    g.resize(n);
    rep(i,m){
      int u, v; cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    color.clear();
    color.resize(n);
    int res = paintable();
    if(res != -1){
      cout << 0 << endl;
      continue;
    }
    set<int> ans;
    int pos = 0, neg = 0;
    rep(i,n)
      if(color[i] == 1) pos++;
      else neg++;
    if(pos % 2 == 0) ans.insert(pos/2);
    if(neg % 2 == 0) ans.insert(neg/2);
    cout << ans.size() << endl;
    for(auto a : ans)
      cout << a << endl;
  }
}
