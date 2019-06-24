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

ll mod_pow(ll a, ll n){
  if(n == 0) return 1;
  if(n % 2 == 0) return mod_pow((a * a) % mod, n/2);
  return (a * mod_pow(a, n-1) % mod);
}

signed main(){
  string s; cin >> s;
  int one = 0;
  int ans = 0;
  rep(i,s.size()-1){
    if(s[i] == '1'){
      int tmp = (mod_pow(2,one) * mod_pow(3,s.size()-i-1)) % mod;
      ans += tmp;
      ans %= mod;
      one++;
    }
    dump(ans);
  }
  ans += mod_pow(2,one);
  ans %= mod;
  if(s[s.size()-1] == '1'){
    one++;
    ans += mod_pow(2,one);
    ans %= mod;
  }
  cout << ans << endl;
}
