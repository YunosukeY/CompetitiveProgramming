#include<bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define pb push_back
using ll  = long long;
using vi  = vector<int>;

int k;
vi small;

bool solve(int mid){ // small[mid]を使わない
  vector<bool> dp(k,false);
  dp[0] = true;
  rep(i,small.size())
    if(i != mid)
      ROF(j,k-small[i],0)
	dp[j+small[i]] = dp[j+small[i]] or dp[j];

  bool res = false;
  FOR(i,k-small[mid],k) res |= dp[i];
  return res;
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
  int n; cin >> n >> k;
  vi a(n); rep(i,n) cin >> a[i];

  // k以上の数は全て必要
  // a[i] < kが必要 <=> a[i]を使って[k,k+a[i])が作れる
  rep(i,n) if(a[i] < k) small.pb(a[i]);
  sort(all(small));

  cout << bs(small.size(),-1) << endl;
}
