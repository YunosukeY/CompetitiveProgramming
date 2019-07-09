#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
typedef long long ll;

vector<vector<int>> g,child;
vector<int> par,d;

int s(int p){ // pを根とする部分木のサイズを返す
  int res = 0;
  rep(i, child[p].size()){
    res += s(child[p][i]);
  }
  return res + 1;
}

void dfs(int s){ // sを根としてdfs
  stack<int> st;
  d[s] = 0;
  st.push(s);
  
  while(!st.empty()){
    int next = st.top();
    st.pop();
    
    rep(i, g[next].size()){
      int c = g[next][i];
      
      if(d[c] == -1){
	// par[c] = next;
	// child[next].push_back(c);
	d[c] = d[next] + 1;
	st.push(c);
      }
    }
  }
}

vector<int> getpath(int t){
  vector<int> path;
  while(t != -1){
    path.push_back(t);
    t = par[t];
  }
  reverse(path.begin(), path.end());
  return path;
}

main(){
  int n,x,y; cin >> n >> x >> y; x--; y--;
  g.resize(n);
  child.resize(n);
  par.resize(n,-1);
  d.resize(n,-1);
  rep(i,n-1){
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b); g[b].push_back(a);
  }
  dfs(x);
}
