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
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  vi l(n+1,-inf), r(n+1,-inf);
  rep(i,n){
    l[i+1] = max(a[i],l[i]);
    r[n-i-1] = max(a[n-i-1],r[n-i]);
  }
  dump(l,r);
  rep(i,n){
    cout << max(l[i],r[i+1]) << endl;
  }
}
