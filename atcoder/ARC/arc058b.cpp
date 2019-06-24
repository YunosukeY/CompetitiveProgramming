#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
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

#define mod 1000000007

ll powmod(ll a, ll b, ll p){ // a^b(mod p)
  if(b == 0) return 1;
  if(b%2 == 0){
    ll d = powmod(a,b/2,p);
    return (d*d)%p;
  }else return (a*powmod(a,b-1,p))%p;
}

main(){
  ll h,w,a,b; cin >> h >> w >> a >> b;
  vector<ll> fact(h+w-1),factinv(h+w-1);

  fact[0] = 1;
  factinv[0] = powmod(fact[0],mod-2,mod);
  for(ll i = 1; i < h + w - 1; i++){
    fact[i] = (fact[i-1] * i) % mod;
    factinv[i] = powmod(fact[i],mod-2,mod);
  }

  ll ans = 0;

  for(ll i = b; i < w; i++){
    ans += (((((((((fact[h-a-1+i] * factinv[h-a-1]) % mod) * factinv[i]) % mod) * fact[a-1+w-1-i]) % mod ) * factinv[a-1]) % mod) * factinv[w-1-i]) % mod;
    ans %= mod;
  }

  cout << ans << endl;
}
