#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
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
  while(1){
    int n,m; cin >> n >> m; if(n == 0 and m == 0) break;
    vvi stu(m,vi(1270));
    int r; cin >> r;
    rep(i,r){
      int t,a,b,s; cin >> t >> a >> b >> s;
      b--;
      if(s) stu[b][t]++;
      else stu[b][t]--;
    }
    rep(i,m) rep(j,1269)
      stu[i][j+1] += stu[i][j];
    //dump(stu);
    int q; cin >> q;
    rep(i,q){
      int ts,te,a; cin >> ts >> te >> a; a--;
      int ans = 0;
      FOR(j,ts,te)
	if(stu[a][j]) ans++;
      cout << ans << endl;
    }
  }
}
