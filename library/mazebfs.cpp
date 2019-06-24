#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
typedef long long ll;

const int inf = 1<<30;

int h, w; // size
vector<string> maze; // 迷路
int sx, sy, gx, gy; // start, goal
vector<vector<int>> d; // distance
vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1}, dy = {0, 1, 0, -1, 1, 1, -1, -1};

bool isin(int x, int y){
  bool ans;
  if(0 <= x and x < h and 0 <= y and y < w) ans = true;
  else ans = false;
  return ans;
}

void bfs(){
  queue<pair<int,int>> q;

  rep(i, h) rep(j, w) d[i][j] = inf;

  q.push(pair<int,int>(sx,sy));
  d[sx][sy] = 0;

  while(not q.empty()){
    pair<int,int> p = q.front();
    q.pop();

    //if(p.fst == gx and p.snd == gy) break;

    rep(i, dx.size()){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(isin(nx,ny) and maze[nx][ny] != '#' and d[nx][ny] == inf){
	q.push(pair<int,int>(nx, ny));
	d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
}

main()
{

}
