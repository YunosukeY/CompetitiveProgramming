#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
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

#define int ll

main(){
  // input
  int n,d,x; cin >> n >> d >> x;
  vvi p(d,vi(n));
  rep(i,d) rep(j,n) cin >> p[i][j];

  rep(i,d-1){ // i日目からi+1日目で増える量を考える
    
    vi inc; // 増えている種類を記録
    rep(j,n) if(p[i+1][j] > p[i][j]) inc.pb(j);

    // 個数制限なしナップザック
    // 容量 : x, 種類数 : inc.size(), j種類目の重さ : p[i][inc[j]], j種類目の価値 : p[i+1][inc[j]] - p[i][inc[j]]
    vvi dp(sz(inc)+1, vi(x+1));
    rep(j, sz(inc)) rep(k, x+1){
      if(k < p[i][inc[j]]) dp[j+1][k] = dp[j][k];
      else dp[j + 1][k] = max(dp[j][k], dp[j + 1][k - p[i][inc[j]]] + (p[i+1][inc[j]] - p[i][inc[j]]));
    }
    x += dp[sz(inc)][x]; // 増加量を足す
    //cout << x << endl;
  }
  cout << x << endl;
}
