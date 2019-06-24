#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
typedef long long ll;
typedef vector<ll> vi;

int main(){
#define int ll
  int n,m; cin >> n >> m;
  vi a(n+1);
  rep(i,n){
    cin >> a[i+1];
    a[i+1] += a[i];
    a[i+1] %= m;
  }
  map<int,int> c;
  int ans = 0;
  rep(i,n+1){
    ans += c[a[i]];
    c[a[i]]++;
  }
  cout << ans << endl;
}
