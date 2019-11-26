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
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

vector<vector<int>> g;
vector<int> par,d;
int ans = 1;
int n, k;
vi data;

void dfs(int s){ // sを根としてdfs
  stack<int> st;
  d[s] = 0;
  st.push(s);
  
  while(!st.empty()){
    int next = st.top();
    st.pop();
    if(next != s){
      ans *= k - data[par[next]];
      ans %= mod;
      data[next] = 2;
      data[par[next]]++;
    }else{
      ans *= k;
      data[s] = 1;
    }
    
    rep(i, g[next].size()){
      int c = g[next][i];
      
      if(d[c] == -1){
	par[c] = next;
	d[c] = d[next] + 1;
	st.push(c);
      }
    }
  }
}

signed main(){
  cin >> n >> k;
  g.resize(n);
  rep(i,n-1){
    int a, b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  d.resize(n,-1);
  par.resize(n,-1);
  data.resize(n,-1);
  dfs(0);
  cout << ans << endl;
}
