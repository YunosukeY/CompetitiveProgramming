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

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

int main(){
  ll h, w; cin >> h >> w;
  vvi c(10, vi(10));
  rep(i, 10) rep(j, 10) cin >> c[i][j];
  rep(k, 10) rep(i, 10) rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

  ll a;
  ll ans = 0;
  rep(i, h) rep(j, w){
    cin >> a;
    if(abs(a) != 1) ans += c[a][1];
  }

  cout << ans << endl;
}
