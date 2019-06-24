#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
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
  while(1){
    int r,n; cin >> r >> n;
    if(r == 0 and n == 0) break;
    map<int,int> maxh;
    FOR(i,-r-1,r+2) maxh[i];
    rep(i,n){
      int nl,nr,h;
      cin >> nl >> nr >> h;
      FOR(j,nl,nr) maxh[j] = max(maxh[j], h);
    }
    if(maxh[r] == 0) maxh[r] = maxh[r-1];
    ROF(i,r,-r+1) maxh[i] = min(maxh[i], maxh[i-1]);
    dump(maxh);
    double ans = inf;
    FOR(i,-r,r+1){
      ans = min(ans, maxh[i] - sqrt(pow(r, 2) - pow(i, 2)));
    }
    printf("%.10f\n",ans + r);
  }
}
