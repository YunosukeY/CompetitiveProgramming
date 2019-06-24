#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;


#define int ll

const int inf = 1ll<<62;
const int mod = 1e9+7;

main(){
  int n,c; cin >> n >> c;
  vi x(n),v(n); rep(i,n) cin >> x[i] >> v[i];
  
  vi a = v; // 時計回り
  reverse(all(v));
  vi b = v; // 逆時計
  // 累積和
  rep(i,n-1){
    a[i+1] += a[i];
    b[i+1] += b[i];
  }
  // 初期位置からの距離を引く
  rep(i,n){
    a[i] -= x[i];
    b[i] -= c - x[n-1-i];
  }

  vi maxa = a, maxb = b;
  // 累積max
  maxa[0] = max(maxa[0], 0ll);
  maxb[0] = max(maxb[0], 0ll);
  rep(i,n-1){
    maxa[i+1] = max(maxa[i+1], maxa[i]);
    maxb[i+1] = max(maxb[i+1], maxb[i]);
  }

  dump(a,b,maxa,maxb);
  
  int ans = max(maxa[n-1], maxb[n-1]);
  
  rep(i,n-1){
    int j = n - 2 - i;
    // 時計回りにi個行ってから戻って反時計
    ans = max(ans, a[i] - x[i] + maxb[j]);
    dump(ans);
    // 逆
    ans = max(ans, b[i] - (c - x[n - 1 - i]) + maxa[j]);
    dump(ans);
  }
  cout << ans << endl;
}
