#include<bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
constexpr int inf = 1ll<<61;

vvi dist(2,vi(1e5,inf));
vector<vector<bool>> visit(2,vector<bool>(1e5,false));
vector<vector<pii>> g(1e5,vector<pii>(2)),f(1e5);
class dijkstra{
public:
  ll ans;

  dijkstra(ll s,ll t){ // sからtへの最短経路
    vector<vector<vector<pii>>> G(2);
    G[0] = move(g);
    G[1] = move(f);
    
    vector<priority_queue<pii,vector<pii>,greater<pii>>> que(2);
    que[0].emplace(dist[0][s]=0,s);
    que[1].emplace(dist[1][t]=0,t);
    ll mu = inf;

    while(!que[0].empty() and !que[1].empty()){
      if(que[0].top().first + que[1].top().first >= mu) break;
      ll k = (que[0].top().first > que[1].top().first)?0:1;
      ll d,v; tie(d,v) = que[k].top();
      que[k].pop();

      if(visit[k^1][v]) goto L;
      visit[k][v] = true;

      rep(i, G[k][v].size()){
	auto n = G[k][v][i];
	ll tmp = d + n.second;
	if(dist[k][n.first] > tmp){
	  mu = min(mu, dist[k][v] + n.second + dist[k^1][n.first]);
	  dist[k][n.first] = tmp;
	  que[k].emplace(tmp,n.first);
	}
      }
    }
  L:
    g = move(G[0]);
    f = move(G[1]);

    ans = inf;
    rep(i,g.size()) ans = min(ans, dist[0][i]+dist[1][i]);
  }
};

main(){
  int k; cin >> k;
  rep(i,k){
    g[i][0] = pii((i+1)%k,1);
    g[i][1] = pii((i*10)%k,0);
    
    f[(i+1)%k].pb(pii(i,1));
    f[(i*10)%k].pb(pii(i,0));
  }
  dijkstra d(1,0);
  cout << d.ans+1 << endl;
}
