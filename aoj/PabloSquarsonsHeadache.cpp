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

#define int ll

main()
{
  while(1){
    int n; cin >> n;
    if(n == 0) break;

    vector<pii> pos(n);
    rep(i,n-1){
      int m,d; cin >> m >> d;
      if(d == 0){
	pos[i+1].fst = pos[m].fst - 1;
	pos[i+1].snd = pos[m].snd;
      }else if(d == 1){
	pos[i+1].fst = pos[m].fst;
	pos[i+1].snd = pos[m].snd - 1;
      }else if(d == 2){
	pos[i+1].fst = pos[m].fst + 1;
	pos[i+1].snd = pos[m].snd;
      }else if(d == 3){
	pos[i+1].fst = pos[m].fst;
	pos[i+1].snd = pos[m].snd + 1;
      }
    }
    int minx = inf, maxx= -inf, miny = inf, maxy = -inf;
    rep(i,n){
      minx = min(minx, pos[i].fst);
      maxx = max(maxx, pos[i].fst);
      miny = min(miny, pos[i].snd);
      maxy = max(maxy, pos[i].snd);
    }
    cout << maxx - minx + 1 << " " << maxy - miny + 1 << endl;
  }
}
