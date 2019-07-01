// Ax = bとなるxを返す
// O(n^3)

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)

typedef double number;
typedef vector<number> arr;
typedef vector<arr> mat;

#define mkrot(x,y,c,s){ double r = sqrt(x*x+y*y); c = x/r; s = y/r;}
#define rot(x,y,c,s){ double u = c*x+s*y; double v = -s*x+c*y; x = u; y = v;}
arr givens(mat A, arr b){
  const int n = b.size();
  rep(i,n) FOR(j,i+1,n){
      double c, s;
      mkrot(A[i][i], A[j][i], c, s);
      rot(b[i], b[j], c, s);
      FOR(k,i,n) rot(A[i][k],A[j][k],c,s);
    }
  ROF(i,n,0){
    FOR(j,i+1,n)
      b[i] -= A[i][j] * b[j];
    b[i] /= A[i][i];
  }
  return b;
}

int main(){
  mat a = {{2,1},{7,-2}}; // 普通に1段目、2段目と入れる
  arr b = {5,1};
  arr x = givens(a,b);
  for(auto xi : x) cout << xi << " ";
  cout << endl;
}
