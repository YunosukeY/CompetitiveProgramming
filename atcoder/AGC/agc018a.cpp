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

ll ext_gcd(ll a,ll b,ll &x,ll &y){ //ax+gy=gcd(a,b)なるx,y,gcd(an,b)を返す
  if(b == 0){
    x = 1; y = 0; return a;
  }
  ll q = a / b;
  ll g = ext_gcd(b, a - q * b, x, y);
  ll z = x - q * y;
  x = y; y = z;
  return g;
}

main(){
  int n,k; cin >> n >> k;
  vi a(n); rep(i, n) cin >> a[i];
  int m = 0; rep(i, n) m = max(m, a[i]);
  int g = a[0], x, y; rep(i, n - 1) g = ext_gcd(g, a[i + 1], x, y);
  if(k <= m and k % g == 0) cout << "POSSIBLE\n";
  else cout << "IMPOSSIBLE\n";
}
