// 各頂点についてそれを根にしたときの高さを求める
// O(E)

Weight visit(const Graph &g, Graph& T, int i, int j){
  if(T[i][j].weight >= 0) return T[i][j].weight;
  T[i][j].weight = g[i][j].weight;
  int u = T[i][j].dst;
  REP(k, T[u].size()){
    if(T[u][k].dst == i) continue;
    T[i][j].weight = max(T[i][j].weight, visit(g,T,u,k)+g[i][j].weight);
  }
  return T[i][j].weight;
}
vector<Weight> height(const Graph& g){
  const int n = g.size();
  Graph T(g); // memoise on tree
  rep(i,n) rep(j,T[i].size())
    T[i][j].weight = -1;
  rep(i,n) rep(j,T[i].size())
    if(T[i][j].weight < 0)
      T[i][j].weight = visit(g, T, i, j);

  vector<Weight> ht(n); // gather results
  rep(i,n) rep(j,T[i].size())
    ht[i] = max(ht[i], T[i][j].weight);
  return ht;
}
