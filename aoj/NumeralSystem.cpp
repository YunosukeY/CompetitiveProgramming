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
  map<char,int> f;
  f['m'] = 1000;
  f['c'] = 100;
  f['x'] = 10;
  f['i'] = 1;
  map<int,char> g;
  g[1000] = 'm';
  g[100] = 'c';
  g[10] = 'x';
  g[1] = 'i';
  int n; cin >> n;
  rep(j,n){
    string s,t; cin >> s >> t;
    int a = 0, b = 0;
    rep(i,sz(s)){
      if(isdigit(s[i])) continue;
      else
	if(i > 0 and isdigit(s[i-1]))
	  a += int(s[i-1] - '0') * f[s[i]];
	else if(i == 0 or (i > 0 and not isdigit(s[i-1])))
	  a += f[s[i]];
    }
    rep(i,sz(t)){
      if(isdigit(t[i])) continue;
      else
	if(i > 0 and isdigit(t[i-1]))
	  b += int(t[i-1] - '0') * f[t[i]];
	else if(i == 0 or (i > 0 and not isdigit(t[i-1])))
	  b += f[t[i]];
    }
    dump(a,b);
    dump(f);
    a += b;
    string ans;
    int x = 1000;
    rep(i,4){
      if(a >= 2 * x)
	ans += (a / x) + '0';
      if(a >= x)
	ans += g[x];
      a %= x;
      x /= 10;
    }
    cout << ans << endl;
  }
}
