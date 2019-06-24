#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#define showvv(v)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

#define MAX 100000
#define int ll

struct node {
  int v, d;
  node(int v, int d):v(v),d(d){}
  bool operator<(const node &n) const { return d > n.d; }
};
struct edge {
  int to, d;
  edge(int to, int d):to(to),d(d){}
};
ll V;
vector<edge> G[MAX];
ll dist[MAX]; // shortest distance

void dijkstra(int s) {
  memset(dist, -1, sizeof(dist));
  priority_queue<node> que;
  que.push(node(s, 0));
  while(!que.empty()){
    int v = que.top().v, d = que.top().d;
    que.pop();
    if(dist[v] >= 0 and dist[v] <= d) continue;
    dist[v] = d;
    for(int i = 0; i < G[v].size(); i++)
      que.push(node(G[v][i].to, d+G[v][i].d));
  }
}

main(){
  int n; cin >> n;
  ll a,b,c;
  rep(i,n-1){
    cin >> a >> b >> c;
    a--; b--;
    G[a].pb(edge(b,c));
    G[b].pb(edge(a,c));
  }

  int q,k; cin >> q >> k; k--;

  dijkstra(k);

  int x,y;
  rep(i,q){
    cin >> x >> y; x--; y--;
    cout << dist[x] + dist[y] << endl;;
  }
  //rep(i,n) cout << dist[i] << endl;
}
