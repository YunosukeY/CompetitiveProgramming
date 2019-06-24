#include<bits/stdc++.h>

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(){
#define int ll
  string s; cin >> s; reverse(all(s));
  vs t = {"dream", "dreamer", "erase", "eraser"};
  rep(i,sz(t)) reverse(all(t[i]));
  dump(t);
  int x = 0, y;
  while(x < sz(s)){
    y = x;
    rep(i,sz(t)){
      if(x + sz(t[i]) <= sz(s) and s.substr(x, sz(t[i])) == t[i])
	x += sz(t[i]);
    }
    if(x == y){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
