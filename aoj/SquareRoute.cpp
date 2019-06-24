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

main()
{
  while(1){
    // 愚直ではO(n^2m^2)
    
    int n,m; cin >> n >> m;
    if(n == 0) break;

    vi h(n+1), w(m+1);
    h[0] = w[0] = 0;
    rep(i,n) cin >> h[i+1];
    rep(i,m) cin >> w[i+1];

    // 累積和 O(n + m)
    rep(i,n) h[i+1] += h[i];
    rep(i,m) w[i+1] += w[i];

    // 和の組み合わせを数える O(n^2 + m^2)
    map<int,int> mph, mpw;
    rep(i,n) rep(j,n-i)
      mph[h[j + i + 1] - h[j]]++;
    rep(i,m) rep(j,m-i)
      mpw[w[j + i + 1] - w[j]]++;

    // 同じものを探す O(n^2 log m)
    int ans = 0;
    for(auto x : mph){
      auto y = mpw.find(x.fst);
      if(y != mpw.end()) ans += x.snd * y->snd;
    }

    cout << ans << endl;
  }
}
