// O(E)

//gが隣接リスト
//gを破壊する
vector<int> EulerianTrail(const int s, vvi &g, const bool directed){
  function<void(int, vector<int> &)> dfs = [&](int u, vi &trail){
    while(!g[u].empty()){
      int v = g[u].back();
      g[u].pop_back();
      if(!directed){
	rep(i,g[v].size()){
	  if(g[v][i] == u){
	    g[v].erase(g[v].begin() + i);
	    break;
	  }
	}
      }
      dfs(v, trail);
    }
    trail.push_back(u);
  };
  vi trail;
  dfs(s, trail);
  reverse(trail.begin(), trail.end());
  return trail;
}

//gが隣接行列
//gを破壊する
vector<int> EulerianTrail(const int s, vector<vector<int>> &g, const bool directed){
  function<void(int, vector<int> &)> dfs = [&](int u, vector<int> &trail){
    rep(v,g.size()) if(g[u][v] > 0){
	g[u][v]--;
	if(!directed) g[v][u]--;
	dfs(v, trail);
      }
    trail.push_back(u);
  };
  vi trail;
  dfs(s, trail);
  reverse(trail.begin(), trail.end());
  return trail;
}
