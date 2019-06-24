#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

main(){
  // 入力
  int h,w; cin >> h >> w;
  vs s(h); rep(i,h) cin >> s[i];

  // 黒の数
  int black = 0;
  rep(i,h) rep(j,w) if(s[i][j] == '#') black++;

  vvi checked(h,vi(w,0)),cost(h,vi(w,1<<29));
  queue<pii> q;
  q.push(pii(0,0));
  checked[0][0]=1;
  cost[0][0]=0;
  while(!q.empty()){
    int x,y;
    x = q.front().first;
    y = q.front().second;
    q.pop();
    rep(k,4){
      int i = x + dx[k];
      int j = y + dy[k];
      if((0<=i)and(i<h)and(0<=j)and(j<w)and(s[i][j]=='.')and(checked[i][j]==0)){
	checked[i][j]=1;
	cost[i][j]=cost[x][y]+1;
	q.push(pii(i,j));
      }
    }
  }
  //rep(i,h){ rep(j,w) cout << checked[i][j] << " "; cout << endl;}

  if(cost[h-1][w-1]==1<<29) cout << -1 << endl;
  else cout << h*w - black - cost[h-1][w-1] - 1 << endl;
}
