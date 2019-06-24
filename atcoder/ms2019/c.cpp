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

class ModCase{ // modの元での場合の数
public:
  vector<ll> fact, finv;

  static ll mod_pow(ll a, ll n){
    if(n == 0) return 1;
    if(n % 2 == 0) return mod_pow((a * a) % mod, n/2);
    return (a * mod_pow(a, n-1) % mod);
  }

  ModCase(ll N):fact(N+1), finv(N+1){ // O(N)で初期化
    fact[0] = 1;
    FOR(i, 1, N+1) fact[i] = (i * fact[i-1]) % mod;
    finv[N] = mod_pow(fact[N],mod-2);
    ROF(i, N, 0) finv[i] = finv[i+1] * (i+1) % mod;
  }

  ll C(ll n, ll r){ // nCr
    if(r < 0 or n < r) return 0;
    return fact[n] * finv[r] % mod * finv[n-r] % mod;
  }

  ll P(ll n, ll r){ // nPr
    if(r < 0 or n < r) return 0;
    return fact[n] * finv[n-r] % mod;
  }

  ll H(ll n, ll r){ // nHr
    return C(n+r-1,r);
  }
};

ll ext_gcd(ll a, ll b, ll &x, ll &y){ // ax+by=gcd(a,b)なるx,y,gcdを返す
  if(b == 0){
    x = 1; y = 0; return a;
  }
  ll q = a / b;
  ll g = ext_gcd(b, a-q*b, x, y);
  ll z = x - q * y;
  x = y; y = z;
  return g;
}

ll invmod(ll a, ll m){ // a^-1(mod m)を返す
  ll x, y;
  ext_gcd(a,m,x,y);
  x %= m;
  if(x < 0) x += m;
  return x;
}

signed main(){
  int n, a, b, c; cin >> n >> a >> b >> c;
  ModCase mc(2*n);
  int an = 1, bn = 1; // a^nとb^n
  rep(i,n){
    an *= a;
    an %= mod;
    bn *= b;
    bn %= mod;
  }
  int h = 1; // (a+b)^n
  int invh = invmod(a+b,mod); // (a+b)^-1
  rep(i,n){
    h *= invh;
    h %= mod;
  }
  int tmpa = 1, tmpb = 1; // a^iとb^i
  int p = 0, q = 0; // p / q
  rep(i,n){
    int tmp = (mc.C(n-1+i,i) * h) % mod;
    p += ((((((n+i) * an) % mod) * tmp) % mod) * tmpb) % mod;
    p %= mod;
    q += (((an * tmp) % mod) * tmpb) % mod;
    q %= mod;
    tmpb *= b;
    tmpb %= mod;
    p += ((((((n+i) * bn) % mod) * tmp) % mod) * tmpa) % mod;
    p %= mod;
    q += (((bn * tmp) % mod) * tmpa) % mod;
    q %= mod;
    tmpa *= a;
    tmpa %= mod;
    h *= invh;
    h %= mod;
  }
  p *= 100;
  p %= mod;
  q *= a+b;
  q %= mod;
  int g = ext_gcd(p,q,a,b);
  p /= g;
  q /= g;
  cout << (p * invmod(q,mod)) % mod << endl;
}
