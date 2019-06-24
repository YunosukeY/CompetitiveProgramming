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

signed main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  bool zero = false;
  rep(i,n) if(a[i] == 0) zero = true;
  bool odd = false;
  rep(i,n) if(a[i] < 0) odd = not odd;
  int ans = 0; rep(i,n) ans += abs(a[i]);
  dump(ans);
  int minv = inf;
  if((not zero) and odd){
    rep(i,n) minv = min(minv, abs(a[i]));
    ans -= 2*minv;
  }
  cout << ans << endl;
}
