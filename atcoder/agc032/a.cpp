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
  vi b(n); iota(all(b),1);
  dump(b);

  vi ans;
  while(a.size()){
    int i = 0;
    while(i < a.size() and a[i] == b[i]) i++;
    dump(i);
    if(i == 0) break;
    i--;
    ans.push_back(a[i]);
    dump(a[i]);
    a.erase(a.begin()+i);
  }

  if(ans.size() == n){
    reverse(all(ans));
    rep(i,n) cout << ans[i] << endl;
  }else{
    cout << -1 << endl;
  }
}
