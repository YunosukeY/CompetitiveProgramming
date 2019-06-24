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

main()
{
  while(1){
    int n,m; cin >> n >> m;
    if(n == 0) break;
    vi sn(n),sm(m);
    int sumn = 0, summ = 0;
    rep(i,n){
      cin >> sn[i];
      sumn += sn[i];
    }
    rep(i,m){
      cin >> sm[i];
      summ += sm[i];
    }
    bool f = false;
    rep(i,n){
      rep(j,m){
	if(sumn - sn[i] + sm[j] == summ - sm[j] + sn[i]){
	  cout << sn[i] << " " << sm[j] << endl;
	  f = true;
	}
	if(f) break;
      }
      if(f) break;
    }
    if(f == false) cout << -1 << endl;
  }
}
