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

signed main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  int sum = accumulate(all(a),0ll);
  vi ans(n);
  for(int i = 0; i < n-1; i+= 2){
    sum -= 2*a[i];
  }
  dump(sum);
  ans[n-1] = sum;
  ROF(i,n-1,0){
    ans[i] = 2 * (a[i] - ans[i+1]/2);
  }
  assert(ans[0]+ans[n-1] == a[n-1] * 2);
  dump(ans);
  cout << ans[0];
  FOR(i,1,n) cout<< " " << ans[i];
  cout << endl;
}
