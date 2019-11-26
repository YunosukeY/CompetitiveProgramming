#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

const double EPS = 1e-8;
using P = complex<double>;
using G = vector<P>;

signed main(){
  int n; cin >> n;
  G g(n);
  rep(i,n){
    double x, y; cin >> x >> y;
    g[i].real(x);
    g[i].imag(y);
  }

  if(n & 1){
    cout << "NA" << endl;
    return 0;
  }

  P res = (g[0] + g[n/2]) * 0.5;
  FOR(i,1,n/2){
    P tmp = (g[i] + g[n/2 + i]) * 0.5;
    if(abs(res - tmp) > EPS){
      cout << "NA" << endl;
      return 0;
    }
  }
  printf("%.10lf %.10lf\n",res.real(),res.imag());
}
