#include<bits/stdc++.h>
using namespace std;

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

class dijkstra{
public:
  vector<vector<pii>> G;
  vector<ll> dist;
  vector<ll> prev;

  dijkstra(ll s,ll t,const vector<vector<pii>> &_G):G(_G){ // sからtへの最短経路
    dist.resize(G.size(),1ll << 59);
    //prev.resize(G.size(),-1);
  
    priority_queue<pii,vector<pii>,greater<pii>> que;
    que.emplace(dist[s] = 0,s);
    
    while(!que.empty()){
      ll v, d; tie(d,v) = que.top();
      que.pop();
      if(v == t) break;
      rep(i, G[v].size()){
	ll tmp = d + G[v][i].second;
	if(dist[G[v][i].first] > tmp){
	  dist[G[v][i].first] = tmp;
	  //prev[G[v][i].first] = v;
	  que.emplace(tmp, G[v][i].first);
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
  ll k; cin >> k;
  vector<vector<pii>> g(k,vector<pii>(2));
  rep(i,k){
    g[i][0] = pii((i+1)%k,1);
    g[i][1] = pii((i*10)%k,0);
  }
  dijkstra d(1,0,g);
  cout << d.dist[0]+1 << endl;
}
