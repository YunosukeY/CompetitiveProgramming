#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
#define SUM(a) accumulate(all(a),int(0))
using ll  = long long;
using vi  = vector<int>;

signed main(){
  int n;
  while(cin >> n, n){
    vi a(n);
    rep(i,n) cin >> a[i];

    int s = SUM(a);
    int ans = 0;
    rep(i,n){
      if(a[i]*n <= s) ans++;
    }
    cout << ans << endl;
  }
}
