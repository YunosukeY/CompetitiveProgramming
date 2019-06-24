#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
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
  int n,K; cin >> n >> K;
  vector<pii> v(n);
  rep(i,n) cin >> v[i].fst >> v[i].snd;

  int ans = inf;
  rep(i,n) rep(j,n) rep(k,n) rep(l,n){
    int xl = min(min(v[i].fst, v[j].fst), min(v[k].fst, v[l].fst));
    int xr = max(max(v[i].fst, v[j].fst), max(v[k].fst, v[l].fst));
    int yl = min(min(v[i].snd, v[j].snd), min(v[k].snd, v[l].snd));
    int yr = max(max(v[i].snd, v[j].snd), max(v[k].snd, v[l].snd));
    int c = 0;
    if(xl == xr or yl == yr) continue;
    rep(m,n) if(xl <= v[m].fst and v[m].fst <= xr and yl <= v[m].snd and v[m].snd <= yr) c++;
    if(K <= c){
      ans = min(ans, (xr - xl) * (yr - yl));
      dump(c);
    }
  }
  cout << ans << endl;    
}
