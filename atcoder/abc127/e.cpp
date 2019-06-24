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

signed main(){
  int n, m, k; cin >> n >> m >> k;

  ModCase mc(n*m);

  int ans = 0;
  FOR(d,1,n){
    ans += d*(n-d)*m*m;
    ans %= mod;
  }
  FOR(d,1,m){
    ans += d*(m-d)*n*n;
    ans %= mod;
  }
  ans *= mc.C(n*m-2,k-2);
  ans %= mod;
  cout << ans << endl;
}
