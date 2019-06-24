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
  int n,m,q; cin >> n >> m >> q;
  vvi im(n+1,vi(n+1));
  rep(i,m){
    int l,r; cin >> l >> r; l--; r--;
    // [0,l]x[r,n)に加算
    im[0][r]++;
    im[0][n]--;
    im[l+1][r]--;
    im[l+1][n]++;
  }
  rep(i,n) rep(j,n)
    im[i+1][j] += im[i][j];
  rep(j,n) rep(i,n)
    im[i][j+1] += im[i][j];

  rep(i,q){
    int a,b; cin >> a >> b;
    cout << im[a-1][b-1] << endl;
  }
}
