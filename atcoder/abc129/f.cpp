#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<ll>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<ll,ll>;
constexpr ll inf = 1ll<<61;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

ll m;

template<class T>
class mat{
public:
  ll n, m;
  vector<vector<T>> a;

  mat(ll n_, T k):n(n_),m(n_){
    a.resize(n);
    rep(i,n){
      a[i].resize(m);
      a[i][i] = k;
    }
  }
  
  mat(const vector<vector<T>> &a_){
    n = a_.size();
    assert(n > 0);
    m = a_[0].size();
    assert(m > 0);
    rep(i,n) assert(m == sz(a_[i]));
    a  = a_;
  }
};

template<class T>
mat<T> operator*(const mat<T> &A, const mat<T> &B){
  assert(A.m == B.n);
  mat<T> C(A.n, B.m, T(0));
  rep(i,C.n) rep(j,C.m) rep(k,A.m){
    C.a[i][j] += (A.a[i][k] * B.a[k][j]) % m;
    C.a[i][j] %= m;
  }
  return C;
}

template<typename T>
T mypow(T a, ll n){  
  T ans(1);
  while(n){
    if(n&1) ans *= a;
    a *= a;
    n = n >> 1;
  }
  return ans;
}

signed main(){
  ll l, a, b; cin >> l >> a >> b >> m;

  mat<ll> res(3,1); // l乗した後の行列
  ll d = 1; // 桁数
  while(l > 0){
    dump(d,l);
    ll powd = mypow(10ll,d); // 10^d
    vvi _ = {{powd,0,0},{1,1,0},{0,b,1}};
    mat<ll> mtr(_); // 累乗する行列
    ll cd = (powd-a)/b - (powd/10-a)/b;
    if(d == 1) cd = (powd-a)/b + 1;
    if(cd > l) cd = l; // 最後
    dump(cd);
    

    l -= cd;
    d++;
    if(d == 20) break;
  }
}
