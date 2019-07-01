#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
typedef long long ll;

class warshallfloyd{
public:
  vector<vector<ll>> dist;
  vector<vector<ll>> prev;

  warshallfloyd(const vector<vector<ll>> &g):dist(g){
    ll n = dist.size();
    prev.resize(n);
    rep(i,n){
      prev[i].resize(n);
      rep(j,n) prev[i][j] = i;
    }
    rep(k,n) rep(i,n) rep(j,n)
      if(dist[i][j] > dist[i][k] + dist[k][j]){
	dist[i][j] = dist[i][k] + dist[k][j];
	prev[i][j] = prev[k][j];
      }
  }

  vector<int> getpath(int s, int t){ // sからtへの最短経路
    vector<int> path;
    while(t != s){
      path.push_back(t);
      t = prev[s][t];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
  }
};

int main(){
  int n,m,r; cin >> n >> m >> r;
  vector<int> go(r); rep(i,r) cin >> go[i];

  ll a,b,c;
  vector<vector<ll>> G(n,vector<ll>(1ll<59));
  rep(i,n) G[i][i] = 0;
  rep(i,m){
    cin >> a >> b >> c;
    a--; b--;
    G[a][b] = G[b][a] = c;
  }

  struct warshallfloyd wf(G);

  rep(i,n){
    rep(j,n) cout << wf.dist[i][j] << " ";
    cout << endl;
  }

  rep(i,n) rep(j,n){
    vector<int> path = wf.getpath(i,j);
    rep(k,path.size()) cout << path[k] << " ";
    cout << endl;
  }
}
