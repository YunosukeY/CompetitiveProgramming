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
  int n;
  while(cin >> n, n){
    vs s(n); rep(i,n) cin >> s[i];

    vi ppos(n,-1); // +の位置
    rep(i,n) rep(j,s[i].size()-1){
      if(s[i][j] != '.') break;
      if(s[i][j+1] == '.') s[i][j] = ' ';
      else{
	ppos[i] = j;
	s[i][j] = '+';
	break;
      }
    }
    //dump(ppos);
    rep(i,n){
      if(ppos[i] == -1) continue;
      //dump(i);
      int d = -1;
      FOR(j,i+1,n){
	if(ppos[j] < ppos[i]) break;
	if(ppos[j] == ppos[i]){
	  d = j;
	  break;
	}
      }
      if(d != -1)
	FOR(j,i+1,d) s[j][ppos[i]] = '|';
    }
    rep(i,n) cout << s[i] << endl;
  }
}
