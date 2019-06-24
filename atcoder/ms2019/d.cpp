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
vi d;
vi ans;
stack<int> st;
priority_queue<int,vi,greater<int>> c;

void dfs(){ // sを根としてbfs  
  while(!st.empty()){
    int next = st.top();
    st.pop();
    d[next]--;
    ans[next] = c.top();
    c.pop();
    
    rep(i, g[next].size()){
      int n = g[next][i];
      if(d[n] > 0) d[n]--;
      if(d[n] <= 0) continue;
      
      if(d[n] == 1){
	st.push(n);
      }
    }
  }
}

signed main(){
  int n; cin >> n;
  g.resize(n);
  d.resize(n);
  ans.resize(n,-1);
  rep(i,n-1){
    int a, b; cin >> a >> b;
    a--; b--;
    d[a]++; d[b]++;
    g[a].pb(b);
    g[b].pb(a);
  }
  
  rep(i,n){
    int tmp; cin >> tmp;
    c.push(tmp);
  }
  rep(i,n){
    if(d[i] == 1){
      st.push(i);
    }
  }
  dfs();
  int ansc = accumulate(all(ans),0ll) - *max_element(all(ans));
  cout << ansc << endl;
  rep(i,n-1) cout << ans[i] << " ";
  cout << ans[n-1] << endl;
}
