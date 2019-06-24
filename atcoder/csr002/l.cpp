#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;

signed main(){
  int n; cin >> n;
  vector<pii> a(n);
  rep(i,n){
    cin >> a[i].first >> a[i].second;
    if(a[i].first < a[i].second) swap(a[i].first,a[i].second);
    a[i].second *= -1;
  }
  sort(all(a));
  vector<pii> dp(n,pii(inf,-inf));
  auto f = [](pii x, pii y){
    return x.first < y.first and x.second > y.second;
  };
  rep(i,n){
    *lower_bound(all(dp),a[i],f) = a[i];
  }
  cout << lower_bound(all(dp),pii(inf,-inf),f)-dp.begin() << endl;
}
