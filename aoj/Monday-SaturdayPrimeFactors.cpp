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

vector<ll> prime(ll n){
  vector<bool> isprime(n+1,false);
  rep(i,sz(isprime)) if(i%7 == 1 or i%7 == 6) isprime[i] = true;
  isprime[1] = false;
  
  vi ans;
  FOR(i,2,n+1)
    if(isprime[i]){
      ans.pb(i);
      for(int j = 2 * i; j <= n; j += i) isprime[j] = false;
    }
  return ans;
}

int main(){
#define int ll
  vi p = prime(300000);
  dump(p);
  
  while(1){
    int n; cin >> n; if(n == 1) break;
    cout << n << ":";
    int i = 0;
    while(1){
      if(p[i] <= n and n % p[i] == 0) cout << " " << p[i];
      else if(p[i] > n) break;
      i++;
      if(i >= sz(p)) break;
    }
    cout << endl;
  }
}
