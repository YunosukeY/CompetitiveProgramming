#include<bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
using ll  = long long;
using vi  = vector<int>;
using pii = pair<int,int>;
constexpr int mod = 1e9+7;

vector<pii> pf(int n){
  vector<pii> res;
  int i = -1;
  FOR(j,2,sqrt(n)+1){
    if(n == 1) break;
    if(n%j == 0){
      res.push_back(pii(j,0));
      i++;
    }
    while(n%j == 0){
      res[i].second++;
      n /= j;
    }
  }
  if(n != 1) res.push_back(pii(n,1));
  return res;
}

class ModuloCombination{
public:
  vector<ll> fact, fact_inv;

  static ll mod_pow(ll a, ll n){
    if(n == 0) return 1;
    if(n % 2 == 0) return mod_pow((a * a) % mod, n/2);
    return (a * mod_pow(a, n-1) % mod);
  }

  ModuloCombination(ll N):fact(N+1), fact_inv(N+1){ // O(N)で初期化
    fact[0] = 1;
    FOR(i, 1, N+1) fact[i] = (i * fact[i-1]) % mod;
    fact_inv[N] = mod_pow(fact[N],mod-2);
    ROF(i, N, 0) fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
  }

  ll op(ll n, ll r){ // nCr
    if(r < 0 or n < r) return 0;
    return fact[n] * fact_inv[r] % mod * fact_inv[n-r] % mod;
  }
};

main(){
  int n,m; cin >> n >> m;
  auto fact = pf(m);

  ModuloCombination C(n+30);
  int res = 1;
  for(auto x : fact){
    int tmp = C.op(n+x.second-1,x.second);
    tmp %= mod;
    res *= tmp;
    res %= mod;
  }
  cout << res << endl;
}
