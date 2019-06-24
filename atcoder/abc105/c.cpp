#include<bits/stdc++.h>
using namespace std;

#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define sz(x) ((ll)(x).size())
#define pb push_back
typedef long long ll;

int main(){
#define int ll
  int n; cin >> n;
  int k = 0;
  vector<bool> ans;
  while(n){
    if(n&1){
      ans.pb(1);
      n -= pow(-1,k);
    }else ans.pb(0);
    n /= 2;
    k++;
  }

  if(sz(ans) == 0) cout << 0 << endl;
  else{
    ROF(i,ans.size(),0) cout << ans[i];
    cout << endl;
  }
}
