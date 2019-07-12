#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

const int MAX_V = 40;
struct Graph{
  int V;
  vector<int> list[MAX_V];
    
  Graph(int n = 0) : V(n) {}
  void init(int n = 0){V = n; rep(i, MAX_V) list[i].clear();}
  inline vector<int>& operator [](int i){return list[i];}
    
  void connect(int f, int t){
    list[f].push_back(t);
    list[t].push_back(f);
  }
};
 
Graph g;
 
int ConnectedCase(Graph &G, vector<bool> can);
int GeneralCase(Graph &G, vector<bool> can);
 
void dfs(Graph &G, int v, vector<bool> &seen, vector<bool> &comp, vector<bool> can){
  seen[v] = true;
  rep(i,G[v].size()){
    int to = G[v][i];
    if(!seen[to] && can[to]) dfs(G, to, seen, comp, can);
  }
  comp[v] = true;
}
 
int ConnectedCase(Graph &G, vector<bool> can){
  int pMax = -1, pMin = -1, Max = -1, Min = MAX_V+1, num = 0;
  rep(i,G.V){
    if(!can[i]) continue;
    int tnum = 0; ++num;
    rep(j,G[i].size()) if(can[G[i][j]]) ++tnum;
    if(Max < tnum) Max = tnum, pMax = i;
    if(Min > tnum) Min = tnum, pMin = i;
  }
  if(num == 1) return 1;
  if(Max <= 2){
    if(Min == 1) return (num+1)/2;
    else return num/2;
  }
  int res = 0;
  if(Min < 2){
    vector<bool> ncan(G.V, 0);
    rep(i,G.V) ncan[i] = can[i];
    ncan[pMin] = false;
    rep(i,G[pMin].size()) ncan[G[pMin][i]] = false;
    res = max(res, GeneralCase(G, ncan) + 1);
  }
  else{
    vector<bool> ncan(G.V, 0);
    rep(i,G.V) ncan[i] = can[i];
    ncan[pMax] = false;
    rep(i,G[pMax].size()) ncan[G[pMax][i]] = false;
    int temp1 = GeneralCase(G, ncan);
    res = max(res, temp1 + 1);

    rep(i,G.V) ncan[i] = can[i];
    ncan[pMax] = false;
    res = max(res, GeneralCase(G, ncan));
  }
  return res;
}
 
int GeneralCase(Graph &G, vector<bool> can){
  if(G.V == 1) return 1;
  vector<bool> seen(G.V, 0);
  int res = 0;
  rep(i,G.V){
    if(!seen[i] && can[i]){
      vector<bool> gcan(G.V, false);
      dfs(G, i, seen, gcan, can);
      res += ConnectedCase(G, gcan);
    }
  }
  return res;
}
 
int StableSet(Graph &G){
  vector<bool> can(G.V, 1);
  return GeneralCase(G, can);
}

signed main(){
  int n, m;
  while(cin >> n >> m, n){
    vvi a(n,vi(m));
    rep(i,n) rep(j,m) cin >> a[i][j];

    g.init(m);
    rep(i,m) FOR(j,i+1,m){ // iとjで上手く行くか
      // a[l][i]とa[k][j]をペアにして、片方ソートした時にもう片方がソートされているか
      vector<pii> tmp(n);
      rep(k,n){
	tmp[k].first = a[k][i];
	tmp[k].second = a[k][j];
      }
      sort(all(tmp));

      bool f = true;
      rep(k,n-1) if(tmp[k].second > tmp[k+1].second) f = false;
      // 補グラフを考えるのでfalseのときに辺を張る
      if(f == false) g.connect(i,j);
    }

    cout << StableSet(g) << endl;
  }
}
