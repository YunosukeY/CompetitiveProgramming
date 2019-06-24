#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
typedef pair<int,int> p;

#define MAX_S 10 // 最大ステップ数
#define MAX_HW 20 // 最大幅、高さ
const int INF = 1<<30;

int h, w;
p s, g;
vector<vector<int>> b(MAX_HW,vector<int>(MAX_HW)), tmpb;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int at(int seq, int index){ // index in [0,MAX_S)での進む方向
  if(index < 0 or MAX_S <= index){
    assert(false);
    return -1;
  }
  int res = seq >> (2*MAX_S - 2*index - 2) & 3; // [0, 4)
  return res;
}

bool isrock(p pt){
  return tmpb[pt.first][pt.second] == 1;
}

bool isin(p pt){
  return (0 <= pt.first and pt.first < w and 0 <= pt.second and pt.second < h);
}

int main(void){
  while(cin >> w >> h, w|h){
    rep(i,h) rep(j,w){
      cin >> b[i][j];
      if(b[i][j] == 2) s = p(i,j);
      else if(b[i][j] == 3) g = p(i,j);
    }

    p now, next;
    int res = INF, resseq;
    vector<vector<int>> resb;
    rep(seq,1<<(2*MAX_S)){ // 進み方全探索
      // init
      tmpb = b;
      now = s;
      //cout << seq << endl;
      rep(i,MAX_S){ // iステップ目
	//cout << i << endl;
	int way = at(seq,i);
	//cout << way << endl;
	next.first = now.first + dx[way]; next.second = now.second +dy[way];
	if(isin(next) and isrock(next)) break; // 隣が石なら動けない

	bool f = false;
	FOR(k,1,MAX_HW){
	  next.first = now.first + k*dx[way]; next.second = now.second +k*dy[way];
	  if(not isin(next)){
	    f = true;
	    break; // 落ちるならダメ
	  }else if(next == g){
	    if(res > i+1){
	      res = i+1;
	      resseq = seq;
	      resb = tmpb;
	    }
	    f = true;
	    break;
	  }else if(isrock(next)){
	    tmpb[next.first][next.second] = 0;
	    now.first = next.first - dx[way]; now.second = next.second - dy[way];
	    break;
	  }
	}
	if(f) break;
      }
    }
    if(10 < res) cout << -1 << endl;
    else{
      rep(i,res) cout << at(resseq,i); cout << endl;
      rep(i,h){ rep(j,w) cout << resb[i][j]; cout << endl; }
      cout << res << endl;
    }
  }

  return 0;
}
