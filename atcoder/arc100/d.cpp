#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
using ll  = long long;
using vi  = vector<ll>;
constexpr ll inf = 1ll<<62;

int main(){
#define int ll
  int n; cin >> n;
  vi a(n+1);
  vi f(n+1,-1),g(n+1,-1);
  rep(i,n){
    cin >> a[i+1];
    a[i+1] += a[i];
  }
  int j = 1;
  FOR(i,2,n-1){
    while(j < i-1 and a[i]/2 > a[j+1]) j++;
    if(abs(a[i]-a[j]*2) > abs(a[i]-a[j+1]*2)) j++;
    f[i] = j;
  }
  j = n-1;
  ROF(i,n-1,2){
    while(j > i+1 and (a[n]-a[i])/2 > (a[n]-a[j-1])) j--;
    if(abs(a[n]+a[i]-a[j]*2) > abs(a[n]+a[i]-a[j-1]*2)) j--;
    g[i] = j;
  }

  int ans = inf;
  rep(i,n+1)
    if(f[i] != -1){
      int maxv = max({ a[f[i]], a[i]-a[f[i]], a[g[i]]-a[i], a[n]-a[g[i]] });
      int minv = min({ a[f[i]], a[i]-a[f[i]], a[g[i]]-a[i], a[n]-a[g[i]] });
      ans = min(ans, abs(maxv-minv));
    }
  cout << ans << endl;
}
