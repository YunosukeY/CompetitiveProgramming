#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const ll inf = 1ll<<62;

int main(){
#define int ll
  int n,k,q; cin >> n >> k >> q;
  vi a(n); rep(i,n) cin >> a[i];

  int res = inf;
  rep(minpos,n){
    vvi tmp(n);
    int m = 0;
    rep(i,n){
      if(a[i] >= a[minpos]) tmp[m].pb(a[i]);
      else m++;
    }
    m++;
    rep(i,m) sort(all(tmp[i]));
    vi take;
    rep(i,m) rep(j,sz(tmp[i])-k+1) take.pb(tmp[i][j]);
    sort(all(take));
    if(sz(take) >= q) res = min(res, take[q-1] - a[minpos]);
  }
  cout << res << endl;
}
