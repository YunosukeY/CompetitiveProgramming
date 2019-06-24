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
    int h,w; cin >> h >> w; if(h == 0) break;
    int s = h*h + w*w;
    bool f = false;
    FOR(i,h+1,sqrt(s)+1){
      int tmp = sqrt(s-i*i);
      if(tmp == 0 or i >= tmp) continue;
      if(s-i*i == tmp * tmp){
	cout << i << " " << tmp << endl;
	f = true;
      }
      if(f) break;
    }
    if(f) continue;
    f = false;
    while(1){
      s++;
      FOR(i,1,sqrt(s)+1){
	int tmp = sqrt(s-i*i);
	if(tmp == 0 or i >= tmp) continue;
	if(s-i*i == tmp * tmp){
	  cout << i << " " << tmp << endl;
	  f = true;
	}
	if(f) break;
      }
      if(f) break;
    }
  }
}
