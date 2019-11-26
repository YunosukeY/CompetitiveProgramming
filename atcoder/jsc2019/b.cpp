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
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define SUM(a) accumulate(all(a),int(0))
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

signed main(){
  int n, k; cin >> n >> k;
  vi a(n); rep(i,n) cin >> a[i];
  vi total(3000), now(3000);
  rep(i,n) total[a[i]]++;
  int ans = 0;
  rep(i,n){
    int tmp = 0;
    rep(j,a[i]) tmp += total[j];
    ans += (tmp*((k*(k-1)/2)%mod))%mod;
    ans %= mod;
    dump(ans, tmp);
    tmp = 0;
    rep(j,a[i]) tmp += total[j] - now[j];
    ans += (k*tmp)%mod;
    dump(ans, tmp);
    ans %= mod;
    now[a[i]]++;
  }
  cout << ans << endl;
}
