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

#define int ll

main(){
  vi p = {5, 12, 17, 24, 31};
  
  while(1){
    int n; cin >> n; if(n == 0) break;

    vs w(n); rep(i,n) cin >> w[i];
    vi l(n+1); rep(i,n) l[i+1] = sz(w[i]);
    rep(i,n) l[i+1] += l[i];

    rep(i,n){
      bool f = true;
      rep(j,5) if(not binary_search(all(l),p[j] + l[i])) f = false;
      if(f){
	cout << i + 1 << endl;
	break;
      }
    }
  }
}
