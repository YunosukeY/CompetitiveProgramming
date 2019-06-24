#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;

int n;
vi a(3);
vi l;

int f(int k, vector<pii> &tmp){
  if(k == n){
    if(tmp[0].second * tmp[1].second * tmp[2].second == 0) return inf;
    int res = 0;
    rep(i,3){
      res += 10 * (tmp[i].second - 1);
      res += abs(tmp[i].first - a[i]);
    }
    return res;
  }else{
    int res = inf;
    rep(i,4){
      tmp[i].first += l[k];
      tmp[i].second++;
      res = min(res, f(k+1, tmp));
      tmp[i].first -= l[k];
      tmp[i].second--;
    }
    return res;
  }
}

signed main(){
  cin >> n;
  rep(i,3) cin >> a[i];
  l.resize(n); rep(i,n) cin >> l[i];

  vector<pii> tmp(4);
  cout << f(0, tmp) << endl;
}
