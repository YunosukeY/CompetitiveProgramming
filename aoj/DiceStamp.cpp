// ジャッジではTLE（手元ではサンプルがあった）

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
using pii = pair<int,int>;

struct die_t{
  int top, front, right, left, back, bottom;
};
#define rotate_swap(x,a,b,c,d) swap(x.a, x.b); swap(x.b, x.c); swap(x.c, x.d);
void rotate_right(die_t& x){ rotate_swap(x,top,left,bottom,right); }
void rotate_left(die_t& x){ rotate_swap(x,top,right,bottom,left); }
void rotate_front(die_t& x){ rotate_swap(x,top,back,bottom,front); }
void rotate_back(die_t& x){ rotate_swap(x,top,front,bottom,back); }

int n;
vector<map<pii,int>> data;
vi memo;
set<pii> dflt;

int rec(int s, set<pii> mask){ // 使ったダイスの集合sと塗られたマスの集合mask
  if(s == (1<<n)-1) return 0;
  if(memo[s] != -1) return memo[s];

  int res = 0;
  rep(i,n){
    if(s>>i&1) continue; // もう使った

    set<pii> tmpmask = mask;
    int tmpres = 0;
    for(auto d : data[i]){
      if(tmpmask.count(d.first)) continue; // 塗られた
      tmpres += d.second;
      tmpmask.insert(d.first);
    }
    int tmpbit = s | (1<<i);
    tmpres += rec(tmpbit, tmpmask);
    res = max(res, tmpres);
  }
  memo[s] = res;
  return res;
}

int main(){
  while(cin >> n, n){
    memo.clear();
    memo.resize(1<<n, -1);
    
    // 各サイコロの軌跡
    data.clear();
    data.resize(n);
    rep(j,n){
      // input
      int x, y, l, r, f, b, dw, u;
      cin >> x >> y >> l >> r >> f >> b >> dw >> u;
      string rot;
      cin >> rot;
      die_t d;
      d.top = u; d.bottom = dw; d.front = f; d.back = b; d.right = r; d.left = l;

      // 軌跡を計算
      data[j][pii(x,y)] = d.bottom;
      rep(i,rot.size()){
	if(rot[i] == 'B'){
	  rotate_back(d);
	  y++;
	}else if(rot[i] == 'R'){
	  rotate_right(d);
	  x++;
	}else if(rot[i] == 'F'){
	  rotate_front(d);
	  y--;
	}else if(rot[i] == 'L'){
	  rotate_left(d);
	  x--;
	}
	data[j][pii(x,y)] = d.bottom;
      }  
    }
    int ans = rec(0,dflt);
    cout << ans << endl;
  }
}
