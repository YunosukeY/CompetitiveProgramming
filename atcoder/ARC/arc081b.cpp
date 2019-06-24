#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

const ll mod = 1e9+7;

int main(){
  int n; cin >> n;
  string s1,s2; cin >> s1 >> s2;
  
  ll ans, pos = 0;
  bool x;
  if(s1[pos] == s2[pos]){
    ans = 3;
    pos++;
    x = true;
  }else{
    ans = 6;
    pos += 2;
    x = false;
  }

  while(pos < n){
    dump(ans);
    if(s1[pos] == s2[pos]){
      if(x) (ans *= 2) %= mod;
      pos++;
      x = true;
    }else{
      if(x) (ans *= 2) %= mod;
      else (ans *= 3) %= mod;
      pos += 2;
      x = false;
    }
  }

  cout << ans << endl;
}
