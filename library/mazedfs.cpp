#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
typedef long long ll;

const int inf = 1<<30;

int h,w;
vector<string> field;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

bool isin(int x, int y){
  bool ans;
  if(0 <= x and x < h and 0 <= y and y < w) ans = true;
  else ans = false;
  return ans;
}

void dfs(int x, int y){
  field[x][y] = '.';

  rep(i,dx.size()){
    int nx = x + dx[i], ny = y + dy[i];
    if(isin(nx, ny) and field[nx][ny] == 'W')
      dfs(nx, ny);
  }
}

int solve(){
  int res = 0;
  rep(i, h) rep(j, w){
    if(field[i][j] == 'W'){
      dfs(i,j);
      res++;
    }
  }
  return res;
}

main()
{

}
