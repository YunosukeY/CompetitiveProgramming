#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0, i##_cond=(n);i<i##_cond;++i)
#define rall(a) (a).rbegin(),(a).rend()

typedef long long ll;
typedef vector<ll> vi;

const ll inf = 1ll<<62;

int main(){
#define int ll
  int n, m; cin >> n >> m;
  vi x(n), y(n), z(n); rep(i,n) cin >> x[i] >> y[i] >> z[i];

  int res = -inf;
  rep(i,2) rep(j,2) rep(k,2){
    vi tmp(n);
    rep(l,n) tmp[l] = pow(-1,i)*x[l] + pow(-1,j)*y[l] + pow(-1,k)*z[l];
    sort(rall(tmp));
    res = max(res, accumulate(tmp.begin(),tmp.begin()+m,0ll));
  }
  cout << res << endl;
}
