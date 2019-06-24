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

int main(){
#define int ll
  int n,m; cin >> n >> m;
  vvi g(n);
  int a,b;
  rep(i,m){
    cin >> a >> b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  vi isin(n);
  list<int> path;
  int tmp = g[0][0];
  path.pb(0); path.pb(tmp);
  g[tmp].erase(find(all(g[tmp]),0));
  g[0].erase(g[0].begin());
  isin[0] = isin[tmp] = 1;
  int s,t;
  while(1){
    if(sz(g[path.front()]) != 0){
      s = g[path.front()][0];
      t = path.front();
      if(isin[s] == 0){
	path.push_front(s);
	isin[s] = 1;
      }
      g[t].erase(g[t].begin());
      g[s].erase(find(all(g[s]),t));
    }else if(sz(g[path.back()])!=0){
      s = g[path.back()][0];
      t = path.back();
      if(isin[s] == 0){
	path.push_back(s);
	isin[s] = 1;
      }
      g[t].erase(g[t].begin());
      g[s].erase(find(all(g[s]),t));
    }else break;
  }
  cout << sz(path) << endl;;
  for(auto x : path){
    if(x == path.front()) cout << x+1;
    else cout << " " << x+1;
  }
  cout << endl;
}
