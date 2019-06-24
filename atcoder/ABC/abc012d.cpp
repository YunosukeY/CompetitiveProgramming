#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
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

#define int ll

#define MAX 300 //最大ノード数

struct node {
  ll v, d;
  node(ll a, ll b):v(a),d(b){}
  bool operator<(const node &n) const { return d > n.d; }
};
struct edge {
  ll to, d;
  edge(ll to, ll d):to(to),d(d){}
};
ll V;
vector<edge> G[MAX];
ll dist[MAX]; // dijkstraの結果の最短経路
int previous[MAX];

void dijkstra(int s) { // sからの最短経路
  rep(i,MAX) dist[i] = 1ll << 59;
  memset(previous, -1, sizeof(previous));
  priority_queue<node> que;
  que.push(node(s, 0));
  dist[s] = 0;
  while(!que.empty()){
    ll v = que.top().v, d = que.top().d;
    que.pop();
    rep(i,sz(G[v])){
      ll tmp = d + G[v][i].d;
      if(dist[G[v][i].to] > tmp){
	dist[G[v][i].to] = tmp;
	previous[G[v][i].to] = v;
	que.push(node(G[v][i].to, tmp));
      }
    }
  }
}

main()
{
  
}
