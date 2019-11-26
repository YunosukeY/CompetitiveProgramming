#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

using Cost = ll;
Cost inf = 1ll<<61;
class node {
public:
  ll v;
  Cost d;
  node(ll _a, Cost _b):v(_a),d(_b){}
  bool operator<(const node &n) const { return d > n.d; }
};
class edge {
public:
  ll to;
  Cost d;
  edge(){}
  edge(ll _to, Cost _d):to(_to),d(_d){}
};
class dijkstra{
public:
  vector<vector<edge>> G;
  vector<Cost> dist;

  dijkstra(ll s,ll t,const vector<vector<edge>> &_G):G(_G){ // sからtへの最短経路
    dist.resize(G.size(),inf);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      dump(dist);
      ll v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	dump(v,G[v][i].to,d,tmp);
	if(dist[G[v][i].to] > tmp/3){
	  if(tmp % 3 == 0)
	    dist[G[v][i].to] = tmp/3;
	  dump(G[v][i].to,tmp);
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }
};

signed main(){
  int n, m; cin >> n >> m;
  vector<vector<edge>> g(n);
  rep(i,m){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(edge(v,1));
  }
  int s, t; cin >> s >> t; s--; t--;
  dijkstra dijk(s,t,g);
  if(dijk.dist[t] == inf) cout << -1 << endl;
  else cout << dijk.dist[t] << endl;
}
