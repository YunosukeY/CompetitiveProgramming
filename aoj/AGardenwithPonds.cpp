#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

vvi f;

int calc_min(int x, int y, int h, int w){
  int minv = inf;
  FOR(i,x,x+h+2){
    chmin(minv, f[i][y]);
    chmin(minv, f[i][y+w+1]);
  }
  FOR(j,y,y+w+2){
    chmin(minv, f[x][j]);
    chmin(minv, f[x+h+1][j]);
  }
  return minv;
}
int calc_max(int x, int y, int h, int w){
  int maxv = -inf;
  FOR(i,x+1,x+h+1) FOR(j,y+1,y+w+1)
    chmax(maxv, f[i][j]);
  return maxv;
}
int calc_cap(int x, int y, int h, int w, int minv){
  int ans = 0;
  FOR(i,x+1,x+h+1) FOR(j,y+1,y+w+1)
    ans += minv - f[i][j];
  return ans;
}

int main(){
  int a, b;
  while(cin >> a >> b, a){
    f.clear();
    f.resize(a, vi(b,0));
    rep(i,a) rep(j,b) cin >> f[i][j];

    int ans = 0;
    FOR(x,0,a-1) FOR(y,0,b-1){ // 枠の左上の点
      FOR(h,1,a-x-1) FOR(w,1,b-y-1){ // 水の幅
	int minv = calc_min(x,y,h,w);
	if(minv <= calc_max(x,y,h,w)) continue;
	chmax(ans, calc_cap(x,y,h,w,minv));
      }
    }
    cout << ans << endl;
  }
}
