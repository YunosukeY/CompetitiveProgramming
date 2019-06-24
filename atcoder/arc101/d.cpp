#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using vi  = vector<ll>;
using pii = pair<ll,ll>;
#define int ll

int n;
vi a;

template<typename T> class BIT{
  vector<T> vec;
  const ll n;
  
public:
  BIT(T _n) : vec(_n + 1), n(_n) {}

  T query(ll x) { /* query for [1, x] */
    T ret = 0;
    for(ll i = x; i > 0; i -= i & (-i)) ret += vec[i];
    return ret;
  }

  void update(ll x, T k) { /* update for [1, x] */
    for(ll i = x; i <= n; i += i & (-i)) vec[i] += k;
  }
};

bool solve(int mid){
  vi s(n+1);
  rep(i,n){
    s[i+1] = (a[i] >= mid) ? 1 : -1;
    s[i+1] += s[i];
  }

  BIT<ll> bit(n*3);
  int inv = 0;
  rep(i,n+1){
    // cout << i << endl;
    inv += bit.query(s[i]+n*2);
    bit.update(s[i]+n*2, 1);
  }

  int tmp = (n+1) * n / 2;
  // cout << (inv >= (tmp+1)/2) << endl;
  if(inv >= (tmp+1) / 2) return true;
  else return false;
}

int bs(int _ok, int _ng){
  int ok = _ok;
  int ng = _ng;

  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;
    if(solve(mid)){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  return ok;
}

main(){
  cin >> n;
  a.resize(n); rep(i,n) cin >> a[i];
  int ans = bs(0,1e9+1);
  cout << ans << endl;
}
