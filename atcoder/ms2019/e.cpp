#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
using ll  = long long;
using vi  = vector<int>;
constexpr ll mod = 1000003;

ll modpow(ll a, ll n){
  if(n == 0) return 1;
  if(n % 2 == 0) return modpow((a * a) % mod, n/2);
  return (a * modpow(a, n-1) % mod);
}

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
  int q; cin >> q;
  vi fact(mod);
  fact[0] = 1;
  FOR(i,1,mod) fact[i] = (i * fact[i-1]) % mod;

  rep(_,q){
    int x, d, n; cin >> x >> d >> n;
    if(x == 0 or n >= mod) cout << 0 << endl;
    else if(d == 0) cout << modpow(x,n) << endl;
    else{
      int xd = (x * invmod(d,mod)) % mod; // x/d
      if(xd + n - 1 >= mod or xd == 0){
	cout << 0 << endl;
	continue;
      }
      int ans = invmod(fact[xd-1],mod);
      ans = (ans * fact[xd+n-1]) % mod; // (x/d)*...*(x/d+n-1)
      ans = (ans * modpow(d,n)) % mod; // (x/d)*...*(x/d+n-1)*x^d
      cout << ans << endl;
    }
  }
}
