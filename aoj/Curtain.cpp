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
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define SUM(a) accumulate(all(a),int(a))
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using P = pair<int,int>;
#define x first
#define y second
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

signed main(){
  int n;
  while(cin >> n, n){
    vector<P> w(n), c(4);
    rep(i,n) cin >> w[i].x >> w[i].y;
    rep(i,4) cin >> c[i].x >> c[i].y;

    vvi qs;
    rep(i,n){
      if(w[i].x == w[(i+1)%n].x)
	qs.push_back({w[i].x,w[i].y,w[(i+1)%n].y,0}); // 窓
    }
    rep(i,4){
      if(c[i].x == c[(i+1)%4].x)
	qs.push_back({c[i].x,c[i].y,c[(i+1)%4].y,1}); // カーテン
    }
    sort(all(qs));
    int ans = 0;
    set<vi> st;
    for(auto q : qs){
      for(auto p : st){
      }
      // [2]は窓の下が0、上が1、カーテンの下が2、上が3
      vi tmpa = {q[1],2*q[3]}, tmpb = {q[2],2*q[3]};
      if(q[1] < q[2])
	tmpa[2] += 1;
      else
	tmpa[1] += 1;
      
      if(q[1] < q[2]) // 削除
	
      else // 追加
	  
    }
    cout << ans << endl;
  }
}
