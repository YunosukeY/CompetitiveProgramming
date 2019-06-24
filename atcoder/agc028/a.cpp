#include<bits/stdc++.h>
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

constexpr int inf = 1ll<<61;
constexpr int mod = 1e9+7;
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

main(){
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;
  int l = lcm(n,m);
  int a = l/n, b = l/m;
  dump(l,a,b);
  bool f = true;
  rep(i,l/(a*b)){
    if(s[i*b] != t[i*a]) f = false;
  }
  if(f) cout << l << endl;
  else cout << -1 << endl;
}
