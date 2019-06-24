#include<bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
using ll  = long long;
using vi  = vector<int>;

constexpr int inf = 1ll<<62;

main(){
  int n,x; cin >> n >> x;
  vi a(n+1);
  rep(i,n){
    cin >> a[i+1];
    a[i+1] += a[i];
  }
  
  mp::cpp_int ans = inf;
  FOR(k,1,n+1){
    mp::cpp_int tmp = (n+k)*x;
    int j = 1;
    for(int i = n; i > 0; i -= k){
      int l = max(0ll,i-k);
      int c = (j == 1 ? 5 : j*2+1);
      tmp += c * (a[i] - a[l]);
      j++;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}
