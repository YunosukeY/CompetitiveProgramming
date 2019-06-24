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
  int n, m; cin >> n >> m;
  vi a(n); rep(i,n) cin >> a[i];
  sort(all(a));
  dump(a);
  map<int,int> mp;
  rep(i,m){
    int b,c; cin >> b >> c;
    mp[c] += b;
  }
  vector<pii> b;
  for(auto x : mp){
    b.pb(pii(min(n,x.second),x.first));
  }
  int ans = 0;
  vector<pii> c(b);
  reverse(all(c));
  dump(c);
  int i = 0;
  rep(j,n){
    dump(j);
    if(i >= c.size()){
      ans += a[j];
    }else if(c[i].first > 0 and c[i].second > a[j]){
      dump(c[i]);
      c[i].first--;
      ans += c[i].second;
      if(c[i].first == 0) i++;
    }else{
      dump(c[i]);
      ans += a[j];
    }
    dump(ans);
  }
  cout << ans << endl;
}
