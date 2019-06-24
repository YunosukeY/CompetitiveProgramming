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

int divisor(int n){ // O(√n)約数列挙
  int res = -inf;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      chmax(res,i);
      if(i * i != n){
	chmax(res,n/i);
	return res;
      }
    }
  }
  return res;
}

signed main(){
  int n; cin >> n;
  vi a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  rep(i,n){
    if(a[i] == b[i]) cout << -1 << endl;
    else{
      cout << divisor(abs(a[i]-b[i])) << endl;
    }
  }
}
