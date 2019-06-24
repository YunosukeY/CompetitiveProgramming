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

vi dx = {1, 0, -1, 0, 1, -1, -1, 1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};

main()
{
  while(1){
    int h,w; cin >> w >> h;
    if(h == 0) break;
    vvi s(h,vi(w));
    rep(i,h) rep(j,w) cin >> s[i][j];
    vvi look(h,vi(w));

    int ans = 0;
    rep(i,h) rep(j,w){
      if(not look[i][j] and s[i][j]){
	ans++;
	queue<pii> q;

	q.push(pii(i,j));
	look[i][j] = 1;

	while(not q.empty()){
	  pii p = q.front();
	  q.pop();

	  rep(k, sz(dx)){
	    int nx = p.fst + dx[k], ny = p.snd + dy[k];
	    if(0 <= nx and nx < h and 0 <= ny and ny < w and s[nx][ny] and look[nx][ny] == 0){
	      q.push(pii(nx, ny));
	      look[nx][ny] = 1;
	    }
	  }
	}
      }
    }
    //dump(look);
    cout << ans << endl;
  }
}
