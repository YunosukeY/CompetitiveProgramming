#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#define showvv(v)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  int n,m,R; cin >> n >> m >> R;
  vi r(R);
  rep(i,R){
    cin >> r[i];
    r[i]--;
  }
  sort(all(r));

  vector<vector<ll>> g(n,vector<ll>(n,1ll<<59));
  ll a,b,c;
  rep(i,m){
    cin >> a >> b >> c;
    a--; b--;
    g[a][b] = g[b][a] = c;
  }
  
  rep(k,n) rep(i,n) rep(j,n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  ll ans = 1ll << 59;
  do{
    ll d = 0;
    rep(i,R-1) d += g[r[i]][r[i+1]];
    ans = min(ans, d);
  }while(next_permutation(all(r)));

  cout << ans << endl;
}
