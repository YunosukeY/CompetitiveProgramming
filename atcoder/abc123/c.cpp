#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using vi  = vector<int>;

signed main(){
  int n; cin >> n;
  vi a(5); rep(i,5) cin >> a[i];
  int minv = *min_element(all(a));
  cout << (n+minv-1)/minv-1+5 << endl;  
}
