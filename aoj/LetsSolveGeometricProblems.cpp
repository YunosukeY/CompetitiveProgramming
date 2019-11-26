#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

int ext_gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1; y = 0; return a;
  }
  int q = a / b;
  int g = ext_gcd(b, a-q*b, x, y);
  int z = x - q * y;
  x = y; y = z;
  return g;
}

map<int,int> pf(int n){
  map<int,int> res;
  FOR(i,2,sqrt(n)+1){
    if(n == 1) break;
    while(n%i == 0){
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n]++;
  return res;
}

int main(){
  int p, q; cin >> p >> q;
  int x, y;
  q /= ext_gcd(p,q,x,y);
  auto pr = pf(q);
  int ans = 1;
  for(auto pa : pr) ans *= pa.first;
  cout << ans << endl;
}
