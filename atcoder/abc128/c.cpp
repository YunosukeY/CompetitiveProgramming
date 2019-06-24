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

signed main(){
  int n, m; cin >> n >> m;
  vi ks(m);
  vvi s(m);
  rep(i,m){
    cin >> ks[i];
    s[i].resize(ks[i]);
    rep(j,ks[i])
      cin >> s[i][j];
  }
  int ans = 0;
  vi p(m);
  rep(i,m) cin >> p[i];

  // 全探索
  rep(i,1<<n){
    // 全てのランプが付いているか確認
    bool f = true;
    rep(j,m){
      int tmp = 0;
      rep(k,s[j].size()){
	//s[j][k]があるか
	if((i>>(s[j][k]-1))&1) tmp++;
      }
      if(tmp % 2 != p[j]) f = false;
    }
    if(f) ans++;
  }
  cout << ans << endl;
}
