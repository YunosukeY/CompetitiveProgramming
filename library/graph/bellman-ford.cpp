#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
typedef long long ll;

#define MAX 100000

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
  vector<bool> nega;
  vector<ll> prev;

  bellmanford(ll s, ll _m, vector<edge> &_G):m(_m),G(_G){ // s:始点
    n = G.size();
    dist.resize(n,1ll << 59);
    prev.resize(n,-1);
    dist[s] = 0;
    
    rep(i, n-1) rep(j, m){
      ll u = G[j].from, v = G[j].to, c = G[j].d;
      if(dist[v] > dist[u] + c){
	dist[v] = dist[u] + c;
	prev[v] = u;
      }
    }      
  }
  
  void negative(){ // sからtへの経路中に負閉路があればnega[t] = true
    nega.resize(n,0);
    rep(i, n) rep(j, m){
      ll u = G[j].from, v = G[j].to, c = G[j].d;
      if(dist[v] > dist[u] + c){
	dist[v] = dist[u] + c;
	nega[v] = true;
      }
      if(nega[u]) nega[v] = true;
    }
  }
  
  vector<int> getpath(int t){
    vector<int> path;
    while(t != -1){
      path.push_back(t);
      t = prev[t];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main(){
  ll n,m; cin >> n >> m;
  int a, b, c;
  vector<edge> G;
  rep(i, m){
    cin >> a >> b >> c;
    a--; b--;
    G.push_back(edge(a, b, c));
  }

  bellmanford bf(0,m,G);
  
  rep(i,n) cout << bf.dist[i] << " "; cout << endl;
  rep(i,n) cout << bf.prev[i] << " "; cout << endl;
  rep(i,n){
    vector<int> path = bf.getpath(i);
    rep(j,path.size()) cout << path[j] << " ";
    cout << endl;
  }

  bf.negative();

  rep(i,n) cout << bf.nega[i] << " "; cout << endl;
}
