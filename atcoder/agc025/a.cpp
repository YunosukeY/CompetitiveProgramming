#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
typedef long long ll;
const ll inf = 1ll<<62;

ll digitsum(ll a){
  int res = 0;
  while(a){
    res += a%10;
    a /= 10;
  }
  return res;
}

int main(){
#define int ll
  int n; cin >> n;

  int ans = inf;
  FOR(i,1,n/2+1)
    ans = min(ans, digitsum(i)+digitsum(n-i));
  cout << ans << endl;
}
