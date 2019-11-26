#include <bits/stdc++.h>
using namespace std;

#include "../../dump.hpp"

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define SUM(a) accumulate(all(a),int(0))
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

struct node{
  ll v, d;
  node(ll _v, ll _d):v(_v),d(_d){}
  bool operator<(const node &n) const { return d > n.d; }
};
struct edge{
  ll from, to, d;
  edge(ll _from, ll _to, ll _d):from(_from),to(_to),d(_d){}
};
class bellmanford{
public:
  ll n,m;
  vector<edge> G;
  vector<ll> dist;
  vector<ll> nega;
  vector<ll> prev;

  bellmanford(ll s, ll _n, vector<edge> &_G):n(_n),G(_G){ // s:始点
    m = G.size();
    dist.resize(n,inf);
    prev.resize(n,-1);
    dist[s] = 0;
    
    rep(i, n-1) rep(j, m){
      ll u = G[j].from, v = G[j].to, c = G[j].d;
      if(dist[u] != inf and dist[v] > dist[u] + c){
	dist[v] = dist[u] + c;
	prev[v] = u;
      }
    }      
  }
  
  void negative(){ // sからtへの経路中に負閉路があればnega[t] = true
    nega.resize(n,0);
    rep(i, n) rep(j, m){
      ll u = G[j].from, v = G[j].to, c = G[j].d;
      if(dist[v] != inf and dist[v] > dist[u] + c){
	dist[v] = dist[u] + c;
	nega[v] = true;
      }
      if(nega[u]) nega[v] = true;
    }
  }
};


signed main(){
  int n, m, p; cin >> n >> m >> p;
  vector<edge> g;
  rep(i,m){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    g.push_back(edge(a,b,-c+p));
  }
  dump(inf);
  bellmanford bf(0,n,g);
  bf.negative();
  dump(bf.nega,bf.dist);
  if(bf.nega[n-1]){
    cout << -1 << endl;
  }else{
    cout << -min(0ll,bf.dist[n-1]) << endl;
  }
}
