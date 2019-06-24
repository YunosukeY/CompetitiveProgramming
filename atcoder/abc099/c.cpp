#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
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

int main(){
#define int ll
  vi a;
  a.pb(1);
  int tmp = 6;
  while(tmp <= 100000){
    a.pb(tmp);
    tmp *= 6;
  }
  tmp = 9;
  while(tmp <= 100000){
    a.pb(tmp);
    tmp *= 9;
  }
  sort(all(a));
  int n; cin >> n;
  vi dp(n+1,inf);
  dp[0] = 0;
  rep(i,n){
    rep(j,sz(a)){
      if(i+1-a[j] >= 0)
	dp[i+1] = min(dp[i+1], dp[i+1-a[j]]+1);
      else
	break;
    }
  }
  cout << dp[n] << endl;
}
