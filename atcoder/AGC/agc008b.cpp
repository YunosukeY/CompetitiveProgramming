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

main()
{
  int n,k; cin >> n >> k;
  vi a(n); rep(i, n) cin >> a[i];
  vi b(n + 1), c(n - k + 1);
  b[0] = 0; rep(i, sz(b) - 1) b[i + 1] = b[i] + max(a[i], 0ll);
  int tmp = 0;
  rep(i, k) tmp += a[i];
  c[0] = max(tmp, 0ll);
  rep(i, sz(c) - 1){
    tmp -= a[i];
    tmp += a[i + k];
    c[i + 1] = max(tmp, 0ll);
  }
  dump(b,c);

  int ans = 0;
  rep(i, sz(c)){
    ans = max(ans, (b[i] - b[0]) + c[i] + (b[sz(b) - 1] - b[i + k]));
  }
  cout << ans << endl;
}
