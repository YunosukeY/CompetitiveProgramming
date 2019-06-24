#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
typedef long long ll;

int main(){
#define int ll
  int n; cin >> n;
  int a; cin >> a;
  int res = 0;
  rep(i,n-1){
    int b; cin >> b;
    if(a == b){
      res++;
      a = -1;
    }else a = b;
  }
  cout << res << endl;
}
