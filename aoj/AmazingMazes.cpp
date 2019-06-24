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

main()
{
  vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
  while(1){
    int h,w; cin >> w >> h;
    if(h == 0) break;

    vvi d(h,vi(w,-1)), in(2*h-1,vi(w));
    rep(i,sz(in)){
      if(i & 1) rep(j,w) cin >> in[i][j];
      else rep(j,w-1) cin >> in[i][j];
    }

    queue<pii> q;
    q.push(pii(0,0));
    d[0][0] = 0;

    while(not q.empty()){
      pii p = q.front();
      q.pop();

      rep(i,4){
	int nx = p.fst + dx[i], ny = p.snd + dy[i];
	if(0 <= nx and nx < h and 0 <= ny and ny < w and d[nx][ny] == -1){
	  dump(nx,ny);
	  bool f = true; // 移動できるかどうか
	  
	  if(p.fst == nx and in[2 * nx][min(p.snd, ny)] == 1) // y方向
	    f = false;
	  else if(p.snd == ny and in[p.fst + nx][ny] == 1) // x方向
	    f = false;
	    
	  if(f){
	    d[nx][ny] = d[p.fst][p.snd] + 1;
	    q.push(pii(nx,ny));
	  }
	}
      }
    }
    dump(d);
    cout << d[h-1][w-1] + 1 << endl;
  }
}
