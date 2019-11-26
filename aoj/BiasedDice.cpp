#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;

struct die_t{
  int top, front, right, left, back, bottom;
};

#define rotate_swap(x,a,b,c,d) swap(x.a, x.b); swap(x.b, x.c); swap(x.c, x.d);
// topがrightになるよう回転
void rotate_right(die_t& x){ rotate_swap(x,top,left,bottom,right); }
void rotate_left(die_t& x){ rotate_swap(x,top,right,bottom,left); }
void rotate_front(die_t& x){ rotate_swap(x,top,back,bottom,front); }
void rotate_back(die_t& x){ rotate_swap(x,top,front,bottom,back); }
// 上から見て時計回りに回転
void rotate_cw(die_t& x){ rotate_swap(x,back,left,front,right); }
void rotate_ccw(die_t& x){ rotate_swap(x,back,right,front,left); }

die_t makeDice(int t, int f){
  die_t res;
  res.top = t;
  res.bottom = 7-t;
  res.front = f;
  res.back = 7-f;

  if((t==1 and f==3) or (t==3 and f==6) or (t==6 and f==4) or (t==4 and f==1)){
    res.left = 2;
    res.right = 5;
  }else if((t==3 and f==1) or (t==6 and f==3) or (t==4 and f==6) or (t==1 and f==4)){
    res.left = 5;
    res.right = 2;
  }else if((t==2 and f==1) or (t==1 and f==5) or (t==5 and f==6) or (t==6 and f==2)){
    res.left = 3;
    res.right = 4;
  }else if((t==1 and f==2) or (t==5 and f==1) or (t==6 and f==5) or (t==2 and f==6)){
    res.left = 4;
    res.right = 3;
  }else if((t==2 and f==4) or (t==4 and f==5) or (t==5 and f==3) or (t==3 and f==2)){
    res.left = 1;
    res.right = 6;
  }else if((t==4 and f==2) or (t==5 and f==4) or (t==3 and f==5) or (t==2 and f==3)){
    res.left = 6;
    res.right = 1;
  }

  return res;
}

vi dx = {0,1,0,-1}, dy = {1,0,-1,0};
#define SIZE 10

int main(){
  int n;
  while(cin >> n, n){
    // 高さとtopの目
    vvi h(SIZE,vi(SIZE)), ts(SIZE,vi(SIZE,-1));
    
    rep(_,n){
      int t, f;
      cin >> t >> f;

      die_t d = makeDice(t,f);

      int x = SIZE/2, y = SIZE/2;
      while(1){
	int dir, num = -1;
	vi pip = {d.right, d.front, d.left, d.back};
	rep(k,4){
	  int nx = x + dx[k], ny = y + dy[k];
	  if(h[x][y] > h[nx][ny] and pip[k] > max(3,num)){
	    dir = k;
	    num = pip[k];
	  }
	}
	if(num == -1) break; // 転がらない

	x += dx[dir];
	y += dy[dir];
	if(dir == 0){
	  rotate_right(d);
	}else if(dir == 1){
	  rotate_front(d);
	}else if(dir == 2){
	  rotate_left(d);
	}else if(dir == 3){
	  rotate_back(d);
	}
      }
      h[x][y]++;
      ts[x][y] = d.top-1;
    }

    vi ans(6);
    rep(i,SIZE) rep(j,SIZE){
      if(ts[i][j] != -1)
	ans[ts[i][j]]++;
    }
    cout << ans[0];
    FOR(i,1,6) cout << " " << ans[i];
    cout << endl;
  }
}
