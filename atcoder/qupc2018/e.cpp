#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
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
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;

constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;

main(){
  int n; cin >> n;
  vi a(n+1); rep(i,n) cin >> a[i+1];
  rep(i,n) a[i+1] += a[i];
  dump(a);
  map<int,int> f,s;

  // 仕切りがa[0]のとき
  f[a[0]]++;
  rep(i,n) s[a[i+1]]++;
  int ans = 0;
  dump(f,s);
  for(auto x : s){
    ans += x.second*(x.second-1)/2;
  }
  dump(ans);

  // 仕切りがa[i+1]のとき
  int prev = ans;
  rep(i,n-1){
    f[a[i+1]]++;
    s[a[i+1]]--;
    int tmp = prev + (f[a[i+1]]-1) - s[a[i+1]];
    dump(f,s);
    dump(tmp);
    ans = min(ans, tmp);
    prev = tmp;
  }
  cout << ans << endl;
}
