#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

int h,w,c;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

bool isin(int x, int y){
  bool ans;
  if(0 <= x and x < h and 0 <= y and y < w) ans = true;
  else ans = false;
  return ans;
}

int changeto(int to,vector<vector<int>> &tmpp){
  queue<pair<int,int>> q;
  int from = tmpp[0][0];
  if(from == to) return 0;

  q.push(pair<int,int>(0,0));
  tmpp[0][0] = to;
  int res = 1;

  while(not q.empty()){
    pair<int,int> p = q.front();
    q.pop();

    rep(i, dx.size()){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(isin(nx,ny) and tmpp[nx][ny] == from){
	q.push(pair<int,int>(nx, ny));
	tmpp[nx][ny] = to;
	res++;
      }
    }
  }
  return res;
}

int rec(int depth,vector<vector<int>> p){
  if(depth == 4){
    changeto(c,p);
    int res = changeto(-1,p);
    return res;
  }

  int res = 0;
  FOR(i,1,7){
    vector<vector<int>> tmpp = p;
    changeto(i,tmpp);
    res = max(res, rec(depth+1, tmpp));
  }
  return res;
}
	      
int main(void){
  while(cin >> h >> w >> c, h){
    vector<vector<int>> p(h,vector<int>(w));
    rep(i,h) rep(j,w) cin >> p[i][j];

    int res = rec(0,p);
    cout << res << endl;
  }
}
