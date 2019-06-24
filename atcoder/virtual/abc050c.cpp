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
  int n; cin >> n;
  map<int, int> mp;
  rep(i,n){
    int a; cin >> a;
    mp[a]++;
  }
  bool f = true;
  if(n % 2 == 0){
    for(int i = 1; i < n; i += 2)
      if(mp[i] != 2)
	f = false;
  }else{
    if(mp[0] != 1) f = false;
    for(int i = 2; i < n; i += 2)
      if(mp[i] != 2)
	f = false;
  }
  if(f){
    int mod = 1000000007;
    int ans = 1;
    rep(i,n/2){
      ans *= 2;
      ans %= mod;
    }
    cout << ans << endl;
  }else
    cout << 0 << endl;
}
