#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;

vi l, p;

int f(int n, int x){ // 1 <= x
  if(n == 0) return 1;

  if(x == 1) return 0;
  else if(1 < x and x < l[n-1] + 2) return f(n-1, x-1);
  else if(x == l[n-1] + 2) return p[n-1] + 1;
  else if(l[n-1] + 2 < x and x < 2 * l[n-1] + 3) return p[n-1] + 1 + f(n-1, x - l[n-1] - 2);
  else if(x == 2 * l[n-1] + 3) return p[n];
  else{
    dump(n,x);
    assert(false);
  }
}

signed main(){
  int n,x; cin >> n >> x;

  l.resize(n+1); p.resize(n+1);
  l[0] = p[0] = 1;
  rep(i,n){
    l[i+1] = 2 * l[i] + 3;
    p[i+1] = 2 * p[i] + 1;
  }

  cout << f(n,x) << endl;
}
