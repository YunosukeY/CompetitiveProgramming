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

signed main(){
  int n; cin >> n;
  vi a(n+1); rep(i,n+1) cin >> a[n-i];
  int gcdv = -1;
  if(a[0]) gcdv = abs(a[0]);

  vvi b(n+1,vi(n+1));
  b[0][0] = 1;
  rep(i,n){
    rep(j,n+1){
      b[i+1][j] = b[i][j];
    }
    rep(j,n){
      b[i+1][j+1] += b[i][j];
    }
    b[i][i] = 0;
  }
  b[n][n] = 0;

  rep(_,n){
    rep(j,n){
      int tmpx = 0;
      FOR(i,j+1,n+1){
	tmpx += b[i][j] * a[i];
      }
      a[j] = tmpx;
    }
    ll x, y;
    if(a[0] and gcdv > 0) gcdv = ext_gcd(gcdv, abs(a[0]),x,y);
    if(gcdv == 1) return 0;
  }

  FOR(i,2,sqrt(gcdv)+2){
    if(gcdv % i == 0) cout << i << endl;
    while(gcdv % i == 0) gcdv /= i;
  }
  if(gcdv != 1) cout << gcdv << endl;
}
