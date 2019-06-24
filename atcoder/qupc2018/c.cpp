#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<ll>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<ll,ll>;

constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;

ll h,w,x;
vs maze;
ll sx, sy, gx, gy; // start, goal
vector<vector<ll>> d; // distance
vector<ll> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

void bfs(){
  queue<pair<int,int>> q;

  q.push(pair<int,int>(sx,sy));
  d[sx][sy] = 0;

  while(not q.empty()){
    pair<int,int> p = q.front();
    q.pop();

    if(p.fst == gx and p.snd == gy) break;

    rep(i, dx.size()){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(maze[nx][ny] != '@' and d[nx][ny] == inf){
	q.push(pair<int,int>(nx, ny));
	d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
}

main(){
  cin >> h >> w >> x;
  maze.resize(h);
  rep(i,h) cin >> maze[i];

  set<pii> st;
  rep(i,h){
    rep(j,w){
      if(maze[i][j] == 'S'){
	sx = i;
	sy = j;
      }else if(maze[i][j] == 'G'){
	gx = i;
	gy = j;
      }else if(maze[i][j] == '@'){
	st.insert(pii(i,j));
      }else if(maze[i][j] == '#'){
	maze[i][j] = '@';
      }
    }
  }
  rep(k,x){
    set<pii> nextst;
    for(auto p : st){
      rep(i,4){
	int nx = p.fst+dx[i], ny = p.snd+dy[i];
	if(maze[nx][ny] != '@'){
	  maze[nx][ny] = '@';
	  nextst.insert(pii(nx,ny));
	}
      }
    }
    st = move(nextst);
  }

  d.resize(h);
  rep(i,h) d[i].resize(w,inf);
  bfs();

  if(d[gx][gy] == inf) cout << -1 << endl;
  else cout << d[gx][gy] << endl;
}
