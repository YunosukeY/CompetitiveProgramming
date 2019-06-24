#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
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

#define int ll

int plustax(int p,int c){ // p : 消費税, c : 税抜価格
  return int(c * double(100 + p) / 100);
}

main()
{
  while(1){
    int x,y,s; cin >> x >> y >> s;

    if(x == 0ll) break;

    int ans = 0;
    FOR(i,1,s){ // 1つ目の商品の値段
      FOR(j,1,s){
	if(plustax(x,i) + plustax(x,j) == s)
	  ans = max(ans, plustax(y,i) + plustax(y,j));
      }
    }

    cout << ans << endl;
  }
}
