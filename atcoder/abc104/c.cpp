#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

int main(){
#define int ll
  int d,g; cin >> d >> g;
  vi p(d),c(d); rep(i,d) cin >> p[i] >> c[i];

  int ans = inf;
  rep(i,1<<d){ // 埋める難易度
    int ac = 0, score = 0;
    rep(j,d) if(i & (1<<j)){ // 埋める
      ac += p[j];
      score += (j+1)*100*p[j] + c[j];
    }
    dump(ac,score);

    // 足りなければ残りの内1番高い問題をできるだけ解く(埋めてはいけない)
    if(score < g)
      ROF(j,d,0){
	if(not (i & (1<<j))){ // 残りの内1番高い問題
	  int need = (g - score + (j+1)*100 - 1) / ((j+1)*100); // 必要問題数
	  if(need > p[j] - 1) // 無理
	    ac = inf;
	  else{ // 可能
	    ac += need;
	  }
	  break;
 	}
      }
    dump(ac);
    ans = min(ans, ac);
  }
  cout << ans << endl;
}
