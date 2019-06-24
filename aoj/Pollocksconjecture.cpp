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

#define n 1000000

int main(){
#define int ll
  int tmp = 1;
  vi a, b;
  while(1){
    int x = tmp * (tmp + 1) * (tmp + 2) / 6;
    if(x >= 1000000) break;
    a.pb(x);
    if(x & 1) b.pb(x);
    tmp++;
  }
  dump(a,b);
  
  vi dpa(n+1,inf),dpb(n+1,inf);
  dpa[0] = 0;
  dpb[0] = 0;
  rep(i,n){
    for(int j = 0; j < sz(a) and a[j] <= i + 1; ++j)
	dpa[i+1] = min(dpa[i+1], dpa[i + 1 - a[j]] + 1);
    for(int j = 0; j < sz(b) and b[j] <= i + 1; ++j)
	dpb[i+1] = min(dpb[i+1], dpb[i + 1 - b[j]] + 1);
  }
  while(1){
    int m;
    cin >> m;
    if(m == 0) break;

    cout << dpa[m] << " " << dpb[m] << endl;
  }
}
