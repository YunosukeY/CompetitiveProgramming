#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
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

bool uni(string s){
  bool f = true;
  rep(i, sz(s) - 1) if(s[0] != s[i + 1]) f = false;
  return f;
}

main(){
#define int ll
  string s; cin >> s;

  int ans = inf;
  rep(i, 26){
    string t = s;
    char c = char('a' + i);
    int count = 0;
    while(not uni(t)){
      string u;
      rep(j, sz(t) - 1)
	if(t[i] == c or t[i + 1] == c) u += c;
	else u += t[i];
      t = u;
      count++;
    }
    ans = min(ans, count);
  }

  cout << ans << endl;
}
