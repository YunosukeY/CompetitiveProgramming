#include <bits/stdc++.h>
//#include "../dump.hpp"
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using vi = vector<int>;
using vvi = vector<vi>;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src_, int dst_, Weight weight_) :
    src(src_), dst(dst_), weight(weight_) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void visit(const Graph &g, int v, vvi &scc,
	   stack<int> &S, vector<bool> &inS,
	   vi &low, vi &num, int& time) {
  low[v] = num[v] = ++time;
  S.push(v); inS[v] = true;
  for(auto e : g[v]) {
    int w = e.dst;
    if (num[w] == 0) {
      visit(g, w, scc, S, inS, low, num, time);
      low[v] = min(low[v], low[w]);
    } else if (inS[w])
      low[v] = min(low[v], num[w]);
  }
  if (low[v] == num[v]) {
    scc.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      scc.back().push_back(w);
      if (v == w) break;
    }
  }
}

// おそらくトポロジカル順の逆
void stronglyConnectedComponents(const Graph& g, vvi &scc) {
  const int n = g.size();
  vi num(n), low(n);
  stack<int> S;
  vector<bool> inS(n);
  int time = 0;
  rep(u, n) if (num[u] == 0)
    visit(g, u, scc, S, inS, low, num, time);
}

void createContractedGraph(const Graph &g, const vvi &scc, vvi & cg){
  cg.resize(scc.size());
  vi id(g.size()); // 縮約前の頂点が縮約後にどこにいるか
  rep(i,scc.size()) rep(j,scc[i].size()){
    id[scc[i][j]] = i;
  }

  rep(i,scc.size()){
    set<int> to; // 各成分の要素の行き先から自分を引いたものが縮約後の行き先
    rep(j,scc[i].size()){
      int now = scc[i][j];
      rep(k,g[now].size()){
	int next = g[now][k].dst;
	to.insert(id[next]);
      }
    }
    to.erase(i);
    cg[i] = move(vi(to.begin(),to.end()));
  }
}

int main(){
  int n;
  while(cin >> n, n){
    vector<double> p(n);
    Graph g(n);
    rep(i,n){
      cin >> p[i];
      int m; cin >> m;
      rep(j,m){
	int a; cin >> a; a--;
	g[i].push_back(Edge(i,a,0));
      }
    }
    vvi scc;
    stronglyConnectedComponents(g,scc);
    //dump(scc);
    vvi cg;
    createContractedGraph(g,scc,cg);
    //dump(cg);
    vi used(cg.size()); // 入次数が0なら0
    rep(i,cg.size()){
      rep(j,cg[i].size()) used[cg[i][j]] = 1;
    }
    //dump(used);
    
    double tmpa = 1.0; // 全ての成分が起きる
    rep(i,used.size()){
      if(used[i] == 1) continue;
      
      double tmpb = 1.0; // 各成分の全員が寝坊する
      for(auto k : scc[i]){
    	tmpb *= p[k];
      }
      tmpa *= (1.0 - tmpb); // 誰かが起きる
    }
    printf("%.10lf\n",tmpa);
  }
}
