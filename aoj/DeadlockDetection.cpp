#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define SUM(a) accumulate(all(a),int(a))
#define uni(a) (a).erase(unique(all(a)),(a).end())
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

vvi g;
vi d;

int dfs(int s){ // sを根としてdfs
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
      }else{
	return c;
      }
    }
  }
  return -1;
}

signed main(){
  int n;
  while(cin >> n, n){
    // input
    string s; cin >> s;

    // 分解
    vs os;
    string tmp;
    rep(i,n){
      if(s[i] == 'u' and tmp != ""){
	os.push_back(tmp);
	tmp.clear();
      }else{
	tmp += s[i];
      }
    }
    // dump(os);

    bool f = true;
    // 3つ以上が衝突するなら2つが衝突するので2つだけ見る
    n = os.size();
    rep(i,n) FOR(j,i,n){
      if(i != j and os[i][0] == os[j][0]) continue;
      
      // 獲得する順に辺を張る
      g.clear();
      g.resize(10);
      rep(k,os[i].size()-1){
	int from = os[i][k] - '0', to = os[i][k+1] - '0';
	g[from].push_back(to);
      }
      rep(k,os[j].size()-1){
	int from = os[j][k] - '0', to = os[j][k+1] - '0';
	g[from].push_back(to);
      }
      rep(x,10){
	sort(all(g[x]));
	uni(g[x]);
      }
      // dump(g);
      
      // 閉路があればデッドロックする
      vi ss{os[i][0]-'0',os[j][0]-'0'};
      for(auto x : ss){
	d.clear();
	d.resize(10,-1);
	int res = dfs(x);
	if(res != -1) f = false;
      }
    }
    if(f) cout << "SAFE" << endl;
    else cout << "UNSAFE" << endl;
  }
}
