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
    int w,h; cin >> w >> h;
    if(w == 0) break;

    vs maze(h); rep(i,h) cin >> maze[i];
    vvi look(h,vi(w));
    int sx, sy;
    rep(i,h) rep(j,w) if(maze[i][j] == '@'){
      sx = i; sy = j;
    }
    
    queue<pii> q;

    q.push(pii(sx,sy));
    int ans = 1;
    look[sx][sy] = 1;

    while(not q.empty()){
      pii p = q.front();
      q.pop();

      //if(p.fst == gx and p.snd == gy) break;

      rep(i, 4){
	int nx = p.fst + dx[i], ny = p.snd + dy[i];
	if(0 <= nx and nx < h and 0 <= ny and ny < w and maze[nx][ny] != '#' and look[nx][ny] == 0){
	  q.push(pii(nx, ny));
	  look[nx][ny] = 1;
	  ans++;
	}
      }
    }
    cout << ans << endl;
  }
}
