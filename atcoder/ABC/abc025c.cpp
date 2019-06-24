#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int b[2][3],c[3][2];


int score(vvi board){
  //rep(i,3) { rep(j,3) cout << board[i][j]; cout << endl; }
  
  int chokudai = 0,chokuko = 0;

  rep(i,2) rep(j,3)
    if(board[i][j] == board[i+1][j]) chokudai += b[i][j];
    else chokuko += b[i][j];
  rep(i,3) rep(j,2)
    if(board[i][j] == board[i][j+1]) chokudai += c[i][j];
    else chokuko += c[i][j];

  //cout << chokudai - chokuko << endl;

  return chokudai - chokuko;
}

int calc(vvi board,int phase){
  if(phase == 9) return score(board);
  
  int s,ret;
  // phaseが偶数ならchokudai
  if(phase % 2 == 0){
    ret = -(1 << 29);
    rep(i,3) rep(j,3)
      if(board[i][j] == -1){
	board[i][j] = 1;
	s = calc(board,phase + 1);
	board[i][j] = -1;
	if(ret < s) ret = s;
      }
    return ret;
  }else{
    ret = 1 << 29;
    rep(i,3) rep(j,3)
      if(board[i][j] == -1){
	board[i][j] = 2;
	s = calc(board,phase + 1);
	board[i][j] = -1;
	if(s < ret) ret = s;
      }
    return ret;
  }
}

main(){
  int sum = 0;
  rep(i,2) rep(j,3){
    cin >> b[i][j];
    sum += b[i][j];
  }
  rep(i,3) rep(j,2){
    cin >> c[i][j];
    sum += c[i][j];
  }

  vvi init = vvi(3,vi(3,-1));
  int s = calc(init,0);
  
  //vvi test = {{2,1,2},{1,1,2},{1,2,1}};
  //int s = score(test);
  
  //cout << s << endl;

  cout << (sum + s) / 2 << endl << (sum - s) / 2 << endl;
}
