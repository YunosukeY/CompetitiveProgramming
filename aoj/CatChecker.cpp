#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
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
  string s; cin >> s;
  vvi dp(s.size(),vi(s.size()+1,0));
  rep(i,s.size()) dp[i][0] = 1;
  FOR(w,1,s.size()+1){ // 幅
    dump(w);
    if(w % 3 != 0) continue;
    
    rep(l,s.size()-w+1){
      dump(l);
      if(s[l] != 'm' or s[l+w-1] != 'w') continue;
      for(int xw = 0; xw != w; xw += 3){ // xw:Xの幅
	if(s[l+xw+1] != 'e') continue;
	if(dp[l+1][xw] == 1 and dp[l+xw+2][w-3-xw] == 1){
	  dp[l][w] = 1;
	  break;
	}
      }
    }
  }
  if(dp[0][s.size()]) cout << "Cat\n";
  else cout << "Rabbit\n";
}
  
