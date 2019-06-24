#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
using ll  = long long;
using vi  = vector<int>;

signed main(){
  int x, y, z, k; cin >> x >> y >> z >> k;
  vi a(x); rep(i,x) cin >> a[i];
  vi b(y); rep(i,y) cin >> b[i];
  vi c(z); rep(i,z) cin >> c[i];

  vi ab;
  rep(i,x) rep(j,y) ab.push_back(a[i]+b[j]);
  sort(rall(ab));
  if(k < ab.size()) ab.erase(ab.begin()+k,ab.end());

  vi abc;
  rep(i,ab.size()) rep(j,z) abc.push_back(ab[i]+c[j]);
  sort(rall(abc));

  rep(i,k) cout << abc[i] << endl;
}
