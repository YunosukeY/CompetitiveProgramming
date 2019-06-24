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

vector<int> divisor(int n){ // O(√n)約数列挙
  vector<int> res;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i * i != n) res.push_back(n/i);
    }
  }
  // sort(res.begin(),res.end());
  return res;
}

signed main(){
  int n; cin >> n;
  vi a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  vi x = divisor(a[0]), y = divisor(b[0]);
  rep(i,y.size()) x.pb(y[i]);
  sort(all(x));
  x.erase(unique(all(x)),x.end());
  vi ok(x.size(),1);
  FOR(i,1,n) rep(j,x.size()){
    if(ok[j] == 1 and a[i] % x[j] != 0 and b[i] % x[j] != 0){
      ok[j] = 0;
    }
  }
  ROF(i,ok.size(),0){
    if(ok[i] == 1){
      cout << x[i] << endl;
      return 0;
    }
  }
}
