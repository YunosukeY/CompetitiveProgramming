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

class two_coloring{ // 無向グラフに対する2-彩色
public:
  ll n;
  ll node; // 2-彩色ができなくなったノード
  vector<ll> color;
  
  two_coloring(const vector<vector<pii>> &g){
    n = g.size();
    color.resize(n);
    node = -1;
    rep(s,n) if(color[s] == 0){
      ll res = dfs(g,s);
      if(res != -1){
	node = res;
	break;
      }
    }
  }

  ll dfs(const vector<vector<pii>> &g, ll s){
    stack<ll> st;
    color[s] = 1;
    st.push(s);

    while(!st.empty()){
      ll i = st.top();
      st.pop();

      rep(j,g[i].size()){
	if(color[j] and color[i] == color[j]){
	  return j;
	}else if(color[j] == 0){
	  color[j] = -color[i];
	  st.push(j);
	}
      }
    }
  }
};

int main(){
  ll n,m; cin >> n >> m;
  vector<vector<pii>> g(n);
  rep(i,m){
    ll u,v,s; cin >> u >> v >> s; u--; v--;
    g[u].pb(pii(v,s));
    g[v].pb(pii(u,s));
  }

  two_coloring tc(g);
  cout << tc.node << endl;
}
