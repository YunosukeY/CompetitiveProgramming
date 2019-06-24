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


#define int ll

const int inf = 1ll<<62;
const int mod = 1e9+7;

main(){
  string s; cin >> s;
  if(sz(s) == 26){
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
      cout << -1 << endl;
    }else{
      ROF(i, sz(s), 0){
	if(s[i] < s[i - 1]) continue;
	vi used(26);
	rep(j, i - 1){
	  cout << s[j];
	  used[s[j] - 'a']++;
	}
	used[s[i-1] - 'a']++;
	//dump(used);
	FOR(j, s[i - 1] - 'a', 26){
	  if(used[j] == 0){
	    cout << char('a' + j) << endl;
	    break;
	  }
	}
	break;
      }
    }
  }else{
    vi used(26);
    rep(i, sz(s)){
      used[s[i] - 'a'] = 1;
    }
    cout << s;
    rep(i, 26)
      if(used[i] == 0){
	cout << char('a' + i) << endl;
	break;
      }
  }
}
