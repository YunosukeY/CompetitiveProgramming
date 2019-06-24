#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>void add(T &a, const T &b){a += b; a %= mod;}

vvi g;
vector<int> d;

void bfs(int s){ // sを根としてbfs
  stack<int> st;
  d[s] = 0;
  st.push(s);
  
  while(!st.empty()){
    int next = st.top();
    st.pop();
    
    rep(i, g[next].size()){
      int c = g[next][i];
      
      if(d[c] == -1){
	d[c] = d[next] + 1;
	st.push(c);
      }
    }
  }
}

signed main(){
  int n, m; cin >> n >> m;
  g.resize(n);
  d.resize(n,-1);
  rep(i,m){
    int x, y, z; cin >> x >> y >> z; x--; y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  int c = 0;
  rep(i,n){
    if(d[i] == -1){
      bfs(i);
      c++;
    }
  }
  cout << c << endl;
}
