#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

constexpr int inf = 1<<30;
constexpr int MAX = 20000;
struct edge { int to, cap, rev; };
vector<edge> G[MAX];
bool used[MAX];

void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, int(G[to].size())});
  G[to].push_back((edge){from, 0, int(G[from].size()-1)});
}

int dfs(int v, int t, int f) {
  if(v == t) return f;
  used[v] = 1;
  rep(i,G[v].size()){
    edge &e = G[v][i];
    if(used[e.to] or e.cap <= 0) continue;
    int d = dfs(e.to, t, min(f, e.cap));
    if(d > 0){
      e.cap -= d;
      G[e.to][e.rev].cap += d;
      return d;
    }
  }
  return 0;
}

int ford_fulkerson(int s, int t) {
  int flow = 0, f;
  while(1){
    memset(used, 0, sizeof(used));
    f = dfs(s, t, inf);
    if(f == 0) return flow;
    flow += f;
  }
}

int vertex_connectivity(const vector<vector<int>> &g, int s, int t){
  rep(i,g.size()){
    add_edge(2*i,2*i+1,1);
    rep(j,g[i].size()){
      add_edge(2*i+1,2*g[i][j],1);
    }
  }
  return ford_fulkerson(2*s+1,2*t);
}

int main(){
  int n, m; cin >> n >> m;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  
  int hx, hy, sx, sy;
  rep(i,n) rep(j,m){
    if(s[i][j] == 'H'){
      hx = i; hy = j;
    }
    if(s[i][j] == 'S'){
      sx = i; sy = j;
    }
  }

  // 隣接している場合は不可能，それ以外のときは可能
  if((hx == sx and abs(hy - sy) == 1) or (abs(hx - sx) == 1 and hy == sy)){
    cout << -1 << endl;
    return 0;
  }

  // 可能な場合はHとSの点連結度が答えとなる
  vector<vector<int>> g(n*m);
  vector<int> dx = {0,1,0,-1}, dy = {1,0,-1,0};
  auto isin = [&](int x, int y){
    return 0 <= x and x < n and 0 <= y and y < m;
  };
  rep(i,n) rep(j,m){
    int u = i*m+j;
    rep(k,4){
      int nx = i + dx[k], ny = j + dy[k];
      if((not isin(nx, ny)) or s[nx][ny] == '#') continue;
      int v = nx*m+ny;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  cout << vertex_connectivity(g, hx*m+hy, sx*m+sy) << endl;
}
