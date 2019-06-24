#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i) // i in [0,n)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // i in [b,a)

#define MAX_N 8
#define MAX_M 30
const double INF = 1<<30;

int n,m,p,a,b;
int t[MAX_N]; // ticket
int d[MAX_M][MAX_M]; // distance
double dp[1<<MAX_N][MAX_M]; // dp[S][v] = 残りチケットの集合がS,現在がvの時の最小コスト

void solve(void){
  // init
  rep(i,1<<n) fill(dp[i],dp[i]+m,INF);
  dp[(1<<n)-1][a] = 0; // 出発前はコスト0
  
  ROF(S, 1<<n, 0) rep(v,m) // 集合SについてSを小さくしながら = チケットを使いながら、都市vについてdp[S][v]の次の遷移を考える
    rep(i,n) if(S >> i & 1) // チケットiについてi in Sのとき
    rep(u,m) if(d[v][u] > 0) // 都市uに対しv->uの道があるなら
      dp[S & ~(1<<i)][u] = min(dp[S & ~(1<<i)][u], dp[S][v] + double(d[v][u])/t[i]); // そのチケットを使って移動
  
  double res = INF;
  rep(S,1<<n){
    res = min(res, dp[S][b]);
    //cout << dp[S][b] << endl;
  }
  
  if(res == INF) cout << "Impossible" << endl;
  else printf("%.10f\n",res);
}

int main(void){
  while(cin >> n >> m >> p >> a >> b, n|m|p|a|b){
    a--; b--;
    rep(i,n) cin >> t[i];

    rep(i,m) fill(d[i],d[i]+m,-1); // 辺がなければ距離-1
    int x,y,z;
    rep(i,p){
      cin >> x >> y >> z; x--; y--;
      d[x][y] = d[y][x] = z;
    }
    //rep(i,m){ rep(j,m) cout << d[i][j]; cout << endl; }

    solve();
  }

  return 0;
}
