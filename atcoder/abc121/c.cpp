#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using pii = pair<int,int>;

signed main(){
  int n, m; cin >> n >> m;
  vector<pii> a(n); rep(i,n) cin >> a[i].first >> a[i].second;
  sort(all(a));
  int c = 0, p = 0;
  rep(i,n){
    if(c + a[i].second >= m){
      p += (m - c) * a[i].first;
      break;
    }else{
      c += a[i].second;
      p += a[i].first * a[i].second;
    }
  }
  cout << p << endl;
}
