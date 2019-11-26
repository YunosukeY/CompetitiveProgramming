#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m, t, p;
  while(cin >> n >> m >> t >> p, n){
    vvi paper(600, vi(600));
    rep(i,n) rep(j,m) paper[i][j] = 1;

    int x = 0, y = 0;
    rep(_,t){
      int d, c;
      cin >> d >> c;
      if(d == 1){
	FOR(i,x,x+c) FOR(j,y,y+m){
	  paper[(x+c)+(x+c-1-i)][j] += paper[i][j];
	}
	x += c;
      }else{
	FOR(i,x,x+n) FOR(j,y,y+c){
	  paper[i][(y+c)+(y+c-1-j)] += paper[i][j];
	}
	y += c;
      }
    }

    rep(_,p){
      int xq, yq;
      cin >> xq >> yq;
      cout << paper[x+xq][y+yq] << endl;
    }
  }
}
