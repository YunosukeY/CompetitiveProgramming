#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) (a).begin(),(a).end()
typedef vector<int> vi;
typedef long long ll;

int main(){
  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  int ans = 0;

  rep(i,30){ // k bit目
    ll tmp = 0; // k bit目が1の数
    ll t = 1ll << k;
    vi c(n),d(n);
    rep(i,n){
      c[i] = a[i] % (2 * t);
      d[i] = b[i] % (2 * t);
    }
    sort(all(d));
    rep(i,n){ // a_i
      tmp += lower_bound(all(d),2*t-c[i]) - lower_bound(all(d),t-c[i]);
      tmp += lower_bound(all(d),4*t-c[i]) - lower_bound(all(d),3*t-c[i]);
    }
    if(tmp % 2 == 1) ans += t;
  }

  cout << ans << endl;
}
