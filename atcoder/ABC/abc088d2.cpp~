#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

main(){
  // 入力
  int h,w; cin >> h >> w;
  vs s(h); rep(i,h) cin >> s[i];

  // 黒の数
  int black = 0;
  rep(i,h) rep(j,w) if(s[i][j] == '#') black++;

  // h*wのグラフの隣接行列
  int size = h * w;
  vvi adj(size,vi(size,1 << 29));
  rep(i,h) rep(j,w) if(s[i][j] == '.'){
    int x, y;
    rep(k,4){
      x = i + dx[k];
      y = j + dy[k];
      if((0 <= x) and (x < h) and (0 <= y) and (y < w) and (s[x][y] == '.'))
	adj[i*w+j][x*w+y] = 1;
    }

    adj[i*w+j][i*w+j] = 0;
  }

  //rep(i,size){ rep(j,size) cout << adj[i][j] << " "; cout << endl;}

  // ワーシャルフロイド
  rep(k,size) rep(i,size) rep(j,size) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

  //rep(i,size){ rep(j,size) cout << adj[i][j] << " "; cout << endl;}

  if(adj[0][h*w-1] == 1 << 29) cout << -1 << endl;
  else cout << h*w - black - adj[0][h*w-1] - 1 << endl;
}
