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
    int a,l; cin >> a >> l;
    if(a == 0 and l == 0) break;
    string s = to_string(a);
    rep(i,l-sz(s)) s.insert(0,"0");
    dump(s);
    vs sq; sq.pb(s);
    string tmp = s;
    bool f = false;
    while(1){
      map<char,int> mp;
      rep(i,sz(tmp)) mp[tmp[i]]++;
      if(sz(tmp) < l) rep(i,l-sz(tmp)) mp['0']++;
      dump(mp);
      string ns;
      for(auto x : mp){
	rep(i,x.snd) ns += x.fst;
      }
      dump(ns);
      int minv = stoi(ns);
      reverse(all(ns));
      int maxv = stoi(ns);
      int ni = maxv - minv;
      tmp = to_string(ni);
      dump(tmp);
      rep(i,sz(sq)) if(sq[i] == tmp){
	cout << i << " " << tmp << " " << sz(sq) - i << endl;
	f = true;
	break;
      }
      if(f) break;
      else sq.pb(tmp);
    }
  }
}
