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

int h,w;
bool isin(int x,int y){
  return 0 <= x and x < h and 0 <= y and y < w;
}

int main(){
#define int ll
  cin >> h >> w;
  vvi a(h,vi(w));
  rep(i,h) rep(j,w){
    cin >> a[i][j];
    a[i][j] &= 1;
  }

  int n = 0;
  vi x1,y1,x2,y2;

  rep(i,h) rep(j,w-1)
    if(a[i][j]){
      n++;
      x1.pb(i+1);
      y1.pb(j+1);
      x2.pb(i+1);
      y2.pb(j+2);
      a[i][j+1] ^= 1;
    }

  rep(i,h-1)
    if(a[i][w-1]){
      n++;
      x1.pb(i+1);
      y1.pb(w);
      x2.pb(i+2);
      y2.pb(w);
      a[i+1][w-1] ^= 1;
    }

  cout << n << endl;
  rep(i,n) cout << x1[i] << " " << y1[i] << " " << x2[i] << " " << y2[i] << endl;
}
