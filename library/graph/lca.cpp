#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;

//// LCA
//// lowest common ancestor(by doubling)
vvi g;
int root;
int V; // ノード数
#define MAX_V 1000000 // 最大ノード数
#define MAX_LOG_V 20 // log2(MAX_V) 
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v,int p,int dis){
  parent[0][v]=p;
  depth[v]=dis;
  for(int i=0;i<g[v].size();i++){
    if(g[v][i]!=p)dfs(g[v][i],v,dis+1);
  }
}

void init(){
  dfs(root,-1,0);
  for(int k=0;k+1<MAX_LOG_V;k++){
    for(int v=0;v<V;v++){
      if(parent[k][v]<0)parent[k+1][v]=-1;
      else parent[k+1][v]=parent[k][parent[k][v]];
    }
  }
}

// u, vのlcaを求めるクエリ
int lca(int u,int v){
  if(depth[u]>depth[v])swap(u,v);
  for(int k=0;k<MAX_LOG_V;k++){
    if((depth[v]-depth[u])>>k&1){
      v=parent[k][v];
    }
  }
  if(u==v)return u;
  for(int k=MAX_LOG_V-1;k>=0;k--){
    if(parent[k][u]!=parent[k][v]){
      u=parent[k][u];
      v=parent[k][v];
    }
  }
  return parent[0][u];
}

int main(void){
  int h, w; cin >> h >> w;

  string _; getline(cin, _);
  vs asc(h+1);
  rep(i,h+1) getline(cin, asc[i]);

  g.resize(h*w);
  rep(i,h){
    rep(j,w){
      int x = i + 1, y = 2 * j + 1;
      // 上
      if(0 < i and asc[x-1][y] == ' ') g[i*w+j].push_back((i-1)*w+j);
      // 左
      if(0 < j and asc[x][y-1] == ' ') g[i*w+j].push_back(i*w+j-1);
      // 下
      if(i < h-1 and asc[x][y] == ' ') g[i*w+j].push_back((i+1)*w+j);
      // 右
      if(j < w-1 and asc[x][y+1] == ' ') g[i*w+j].push_back(i*w+j+1);
    }
  }

  V = h*w;
  root = 0;
  init();
  
  int m; cin >> m;
  vi q(m);
  rep(i,m){
    int x, y; cin >> x >> y;
    int u = (x-1)*w+y-1;
    q[i] = u;
  }

  int ans = 0;
  rep(i,m-1){
    ans += depth[q[i]] + depth[q[i+1]] - 2*depth[lca(q[i],q[i+1])];
  }
  cout << ans << endl;
}
