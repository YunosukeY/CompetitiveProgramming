#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define MAX 100000 //最大ノード数

struct node {
  ll v, d;
  node(ll _a, ll _b):v(_a),d(_b){}
  bool operator<(const node &n) const { return d > n.d; }
};
struct edge {
  ll to, d;
  edge(ll _to, ll _d):to(_to),d(_d){}
};
struct dijkstra{
  vector<vector<edge>> G;
  vector<ll> dist;
  vector<ll> prev;

  dijkstra(ll s,const vector<vector<edge>> &_G):G(_G){ // sからの最短経路
    dist.resize(G.size(),1ll << 59);
    //prev.resize(G.size(),-1);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      ll v = que.top().v, d = que.top().d;
      que.pop();
      
      rep(i, G[v].size()){
	ll tmp = d + G[v][i].d;
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

int main(){
#define int ll
  int n,m,s,t; cin >> n >> m >> s >> t; s--; t--;
  vector<vector<edge>> yeng(n),snukeg(n);
  rep(i,m){
    int u,v,a,b;
    cin >> u >> v >> a >> b; u--; v--;
    yeng[u].pb(edge(v,a));
    yeng[v].pb(edge(u,a));
    snukeg[u].pb(edge(v,b));
    snukeg[v].pb(edge(u,b));
  }
  struct dijkstra yen(s,yeng);
  struct dijkstra snuke(t,snukeg);

  vi can(n);
  rep(i,n){
    can[i] += yen.dist[i] + snuke.dist[i];
  }
  ROF(i,n-1,0) can[i] = min(can[i],can[i+1]);

  rep(i,n){ // i未満はだめ
    cout << 1000000000000000ll - can[i] << endl;
  }
}
