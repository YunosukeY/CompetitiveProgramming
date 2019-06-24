#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
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
  int m; cin >> m;

  rep(i,m){
    string s; cin >> s;

    set<string> st;
    rep(j,sz(s) - 1){ // jとj+1で分ける
      string l = s.substr(0,j+1), r = s.substr(j+1,sz(s)-j);
      
      vs vsl, vsr;
      vsl.pb(l); reverse(all(l)); vsl.pb(l);
      vsr.pb(r); reverse(all(r)); vsr.pb(r);

      rep(k,sz(vsl)) rep(n,sz(vsr)){
	st.insert(vsl[k] + vsr[n]);
	st.insert(vsr[n] + vsl[k]);
      }
    }

    cout << st.size() << endl;
    //dump(st);
  }
}
