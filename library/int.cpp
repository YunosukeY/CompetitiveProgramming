#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
const ll mod = 1e9+7;

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

vector<ll> makeModInv(int n){ // 1~nのmodでの逆元をO(n)で前計算
  vector<ll> res(n+1);
  res[1] = 1;
  FOR(i,2,n+1) res[i] = mod - res[mod%i] * (mod/i) % mod;
  return res;
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

ll lcm(ll a, ll b){
  ll x, y;
  return a * b / ext_gcd(a,b,x,y);
}

template<typename T>
T mypow(T a, ll n){
  bool f = (n < 0);
  n = abs(n);
  
  T ans(1);
  while(n){
    if(n&1) ans *= a;
    a *= a;
    n = n >> 1;
  }

  if(f) ans = T(1) / ans;
  return ans;
}

ll fib(ll n){
  return mypow((1+sqrt(5))/2,n)/sqrt(5)+0.5;
}

int main(){
  FOR(i,-10,10) cout << mypow(2.0,i) << endl;
  return 0;
}
