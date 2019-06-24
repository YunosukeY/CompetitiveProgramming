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

template <class T>
class fenwick_tree {
public:
  vector<T> x;
  fenwick_tree(int n) : x(n, 0) { }
  T sum(int i, int j) {
    if (i == 0) {
      T S = 0;
      for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else return sum(0, j) - sum(0, i-1);
  }
  void add(int k, T a) {
    for (; k < x.size(); k |= k+1) x[k] += a;
  }
};

int main(){
#define int ll
  int n; cin >> n;
  vi wpos(n+1,-1),bpos(n+1,-1);
  vs c(2*n);
  vi a(2*n);
  rep(i,2*n){
    cin >> c[i] >> a[i];
    if(c[i] == "W") wops[a[i]] = i;
    else bpos[a[i]] = i;
  }

  vvi costw(n+1,vi(n+1)),costb(n+1,vi(n+1));
  fenwick_tree white(n),black(n);
  
  
  vvi dp(n+1,vi(n+1,inf));
  dp[0][0] = 0;
  rep(i,n+1) rep(j,n+1){
    if(i == 0 and j == 0) continue;
    if(i != 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + );
    if(j != 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + );
  }
  cout << dp[n][n] << endl;
}
