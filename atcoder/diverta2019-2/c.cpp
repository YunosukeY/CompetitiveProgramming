#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

signed main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  sort(rall(a));
  priority_queue<int> qa; // 正
  priority_queue<int,vi,greater<int>> qb; // 負
  FOR(i,1,n-1){
    if(a[i] >= 0) qa.push(a[i]);
    else qb.push(a[i]);
  }
  dump(qa,qb);
  vector<pii> seq;
  int ans = a[n-1];
  while(not qa.empty()){
    seq.emplace_back(ans, qa.top());
    ans = ans - qa.top();
    qa.pop();
  }
  seq.emplace_back(a[0],ans);
  ans = a[0] - ans;
  while(not qb.empty()){
    seq.emplace_back(ans, qb.top());
    ans = ans - qb.top();
    qb.pop();
  }

  cout << ans << endl;
  rep(i,seq.size()){
    cout << seq[i].first << " " << seq[i].second << endl;
  }
}
