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

int maxn = 10000000;

main(){
  while(1){
    int m,n; cin >> m >> n;
    if(m == 0) break;

    vector<bool> isprime(maxn, false);
    int i = m, c = 0;
    while(1){
      if(isprime[i] == false){
	c++;
	for(int j = i; j < maxn; j += i)
	  isprime[j] = true;
      }
      i++;
      if(i == maxn) break;
      if(c == n) break;
    }
    FOR(j,m,maxn) if(isprime[j] == false){
      cout << j << endl;
      break;
    }
  }
}
