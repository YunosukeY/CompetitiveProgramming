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

struct RollingHash {
  typedef long long int_type;
  typedef pair<int_type,int_type> hash_type;

  int_type base1;
  int_type base2;
  int_type mod1;
  int_type mod2;
  vector<int_type> hash1;
  vector<int_type> hash2;
  vector<int_type> pow1;
  vector<int_type> pow2;

  RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

  void init(const string &s) {
    int n = s.size();

    hash1.assign(n+1,0);
    hash2.assign(n+1,0);
    pow1.assign(n+1,1);
    pow2.assign(n+1,1);

    for(int i=0;i<n;i++) {
      hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;
      hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;
      pow1[i+1] = pow1[i] * base1 % mod1;
      pow2[i+1] = pow2[i] * base2 % mod2;
    }
  }

  hash_type get(int l,int r) {
    int_type t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
    int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
    return make_pair(t1, t2);
  }

  RollingHash::hash_type concat(hash_type h1, hash_type h2, int h2_len) {
    return make_pair((h1.first*pow1[h2_len]+h2.first)%mod1, (h1.second*pow2[h2_len]+h2.second)%mod2);
  }

};

signed main(){
  int n; cin >> n;
  string s; cin >> s;

  RollingHash rh;
  rh.init(s);

  int ans = 0;
  rep(i,n) FOR(j,i+1,n){ // i : 左, j : 右
    int ok = 0;
    int ng = n;
    while(abs(ok - ng) > 1){
      int mid = (ok + ng) / 2; // 文字数

      bool f;
      if(i+mid <= j and j+mid <= n){
	if(rh.get(i,i+mid) == rh.get(j,j+mid))
	  f = true;
	else f = false;
      }else{
	f = false;
      }
      
      if(f){
	ok = mid;
      }else{
	ng = mid;
      }
    }
    chmax(ans,ok);
  }
  cout << ans << endl;
}
