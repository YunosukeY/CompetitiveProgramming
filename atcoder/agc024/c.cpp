#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define int ll

main()
{
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];

  // 可能か
  if(a[0] != 0){
    cout << -1 << endl;
    return 0;
  }
  int zeropos = 0;
  FOR(i,1,n){
    if(a[i] == 0){
      zeropos = i;
    }else if(a[i] <= i - zeropos){
    }else{
      cout << -1 << endl;
      return 0;
    }
  }

  // 何回か
  int ans = 0;
  rep(i,n-1){
    if(a[i+1] <= a[i]){
      ans += a[i];
    }else if(a[i+1] == a[i]+1){
    }else{
      cout << -1 << endl;
      return 0;
    }
  }
  ans += a[n-1];
  cout << ans << endl;
}
