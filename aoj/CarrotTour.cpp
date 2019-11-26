#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

using vi = vector<int>;
using vvi = vector<vi>;
using P = complex<double>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
const double EPS = 1e-8;
#define SIZE 1e4+5

int main(){
  int n; cin >> n;
  double r, theta; cin >> r >> theta;
  theta *= M_PI/180.0;
  vector<P> ps(n);
  rep(i,n){
    double x, y; cin >> x >> y;
    ps[i] = P(x,y);
  }

  vector<vvi> can(n,vvi(n));
  rep(i,n) rep(j,n){
    if(i == j) continue;
    rep(k,n){
      if(j == k) continue;
      if(abs(arg((ps[j]-ps[i])/(ps[k]-ps[j]))) - EPS < theta){
	can[i][j].push_back(k);
      }
    }
  }

  vvvd dp(n+1, vvd(n, vd(SIZE)));
  dp[n][0][0] = r; // 前の場所がないことをn->で表す
  rep(k,SIZE-1) rep(i,n+1) rep(j,n){
    if(i == n){
      FOR(x,1,n) chmax(dp[j][x][k+1] , dp[i][j][k] - abs(ps[j]-ps[x]));
    }else{
      for(auto x : can[i][j]){
	chmax(dp[j][x][k+1] , dp[i][j][k] - abs(ps[j]-ps[x]));
      }
    }
  }
  int ans = 0;
  rep(i,n+1) rep(j,n) rep(k,SIZE){
    if(dp[i][j][k] > EPS){
      chmax(ans, k);
    }
  }
  cout << ans << endl;
}
