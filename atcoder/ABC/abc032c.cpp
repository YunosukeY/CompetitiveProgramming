#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()

typedef vector<int> vi;

int main(){
  int n, k; cin >> n >> k;
  vi s(n); rep(i, n) cin >> s[i];
  
  if(any_of(all(s), [](int x){ return x == 0; })){
    cout << n << endl;
    return 0;
  }

  int r = 0;
  int mul = 1, res = 0;
  rep(l, n){
    while(r < n and mul * s[r] <= k){
      mul *= s[r];
      r++;
    }
    res = max(res, r - l);
    if(mul % s[l]) mul /= s[l];
    else r = l+1;
  }
  cout << res << endl;
}
