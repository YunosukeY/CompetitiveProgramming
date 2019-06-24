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
  while(1){
    int n; cin >> n; if(n == 0) break;
    vi p(26);
    bool fa = true;
    vector<char> c(n); rep(i,n) cin >> c[i];
    rep(i,n){
      p[int(c[i] - 'A')]++;
      int f = 0, s = 0, pos;
      rep(j,26){
	if(f <= p[j]){
	  s = f;
	  pos = j;
	  f = p[j];
	}else if(s < p[j] and p[j] < f){
	  s = p[j];
	}
      }
      if(f > s + (n - 1 - i)){
	//dump(f,s,n-1-i);
	cout << char(pos + 'A') << " " << i + 1 << endl;
	fa = false;
	break;
      }
    }
    if(fa) cout << "TIE" << endl;
  }
}
    
