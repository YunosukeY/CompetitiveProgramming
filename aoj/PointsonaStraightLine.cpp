#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

// 点
typedef complex<int> P;
// 外積
int cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
// 内積
int dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

// a->b->cという折れ線がどうなっているか
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // 反時計周り
  if (cross(b, c) < 0)   return -1;       // 時計回り
  if (dot(b, c) < 0)     return +2;       // c--a--b の順に一直線
  if (norm(b) < norm(c)) return -2;       // a--b--c の順に一直線
  return 0;
}

signed main(){
  int n, v; cin >> n >> v;
  vector<P> ps;
  rep(i,n){
    int x, y; cin >> x >> y;
    ps.emplace_back(x,y);
  }

  rep(i,n) FOR(j,i+1,n){
    int tmp = 2;
    FOR(k,j+1,n)
      if(abs(ccw(ps[i],ps[j],ps[k])) == 2) tmp++;
    if(tmp >= v){
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
