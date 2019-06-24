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
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>void add(T &a, const T &b){a += b; a %= mod;}

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
  vector<ll> prev;

  dijkstra(ll s,const vector<vector<edge>> &_G):G(_G){ // sからの最短経路
    dist.resize(G.size(),inf);
    //prev.resize(G.size(),-1);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      ll v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  //prev[G[v][i].to] = v;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }

  dijkstra(ll s,ll t,const vector<vector<edge>> &_G):G(_G){ // sからtへの最短経路
    dist.resize(G.size(),inf);
    //prev.resize(G.size(),-1);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      ll v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      if(v == t) break;
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  //prev[G[v][i].to] = v;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }

  vector<ll> getpath(ll t){ // tへの最短経路を返す
    vector<ll> path;
    while(t != -1){
      path.push_back(t);
      t = prev[t];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

signed main(){
  int n; cin >> n;
  vector<vector<edge>> g(n);
  rep(i,n-1){
    int u,v,w; cin >> u >> v >> w; u--; v--;
    g[u].pb(edge(v,w));
    g[v].pb(edge(u,w));
  }
  dijkstra d(0,g);
  rep(i,n){
    if(d.dist[i]%2==0) cout << 0 << endl;
    else cout << 1 << endl;
  }
}
