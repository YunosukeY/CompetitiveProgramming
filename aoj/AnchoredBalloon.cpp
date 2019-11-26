#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr double inf = 1e10;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

vvi data;

#define maxLoop 100
double f(double x, double y){
  double minv = inf;
  rep(i,data.size()){
    double nrm1 = pow(x-data[i][0],2) + pow(y-data[i][1],2);
    double nrm2 = pow(data[i][2],2) - nrm1;
    chmin(minv, nrm2);
  }
  // dump(x,y,minv);
  return minv;
}

double searchy(double x, double left = -100, double right = 100){
  for(int loop = 0; loop < maxLoop; ++loop){
    if(f(x, (left*2+right)/3) > f(x, (left+right*2)/3)){
      right = (left + right * 2) / 3;
    }else{
      left = (left * 2 + right) / 3;
    }
  }
  return f(x,(right + left) * 0.5);
}
double searchx(double left = -100, double right = 100){
  for(int loop = 0; loop < maxLoop; ++loop){
    //dump(left, right, searchy((left*2+right)/3), searchy((left+right*2)/3));
    if( searchy((left*2+right)/3) > searchy((left+right*2)/3) ){
      right = (left + right * 2) / 3;
    }else{
      left = (left * 2 + right) / 3;
    }
  }
  //dump((right+left)/2);
  return searchy((right+left)*0.5, -100, 100);
}

signed main(){
  int n;
  while(cin >> n, n){
    data.clear();
    data.resize(n,vi(3));
    rep(i,n) rep(j,3) cin >> data[i][j];
    printf("%.10lf\n", sqrt(searchx()));
  }
}
