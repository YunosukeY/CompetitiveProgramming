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
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

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

ll lcm(ll a, ll b){
  ll x, y;
  return a * b / ext_gcd(a,b,x,y);
}


signed main(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  int x = (b+c)/c - (a+c-1)/c;
  int y = (b+d)/d - (a+d-1)/d;
  int l = lcm(c,d);
  int z = (b+l)/l - (a+l-1)/l;
  cout << (b-a+1) - (x+y-z) << endl;
}
