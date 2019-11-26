#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
constexpr int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

int h, w, s;
vvi u;
vvi sum;

int f(int lx, int ly, int ux, int uy){
  return sum[ux][uy] - sum[ux][ly] - sum[lx][uy] + sum[lx][ly];
}

map<vi,pii> memo;

pii rec(int lx, int ly, int ux, int uy){
  // その領域を停電させても足りない
  if(f(lx,ly,ux,uy) < sum[h][w] - s){
    return pii(-inf,-inf);
  }

  vi in = {lx,ly,ux,uy};
  if(memo.count(in)) return memo[in];

  // その領域を1つの区画としたときの答え
  pii ans{1,f(lx,ly,ux,uy)+s-sum[h][w]};
  FOR(i,lx+1,ux){ // 上下で分割したとき
    pii resl = rec(lx,ly,i,uy);
    pii resu = rec(i,ly,ux,uy);
    pii tmpres{resl.first+resu.first, min(resl.second,resu.second)};
    chmax(ans, tmpres);
  }
  FOR(j,ly+1,uy){ // 左右で分割した時
    pii resl = rec(lx,ly,ux,j);
    pii resu = rec(lx,j,ux,uy);
    pii tmpres{resl.first+resu.first, min(resl.second,resu.second)};
    chmax(ans, tmpres);
  }
  memo[in] = ans;
  return ans;
}

int main(){
  while(cin >> h >> w >> s, h){
    u.clear();
    u.resize(h,vi(w));
    rep(i,h) rep(j,w) cin >> u[i][j];
    sum.clear();
    sum.resize(h+1,vi(w+1));
    rep(i,h) rep(j,w)
      sum[i+1][j+1] = u[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
    pii ans = rec(0,0,h,w);
    cout << ans.first << " " << ans.second << endl;
  }
}
