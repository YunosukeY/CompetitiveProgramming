#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
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

vi prime(int n){ // n以下の素数を要素に持つviを返す
  vector<bool> isprime(n+1,true);
  vi ans;
  isprime[0] = isprime[1] = false;
  FOR(i,2,n+1)
    if(isprime[i]){
      ans.pb(i);
      for(int j = 2 * i; j <= n; j += i) isprime[j] = false;
    }
  return ans;
}

main()
{
  vi p = prime(55555);
  ROF(i,sz(p),0) if(p[i] % 5 != 1) p.erase(p.begin() + i);

  //cout << sz(p) << endl;

  int n; cin >> n;
  rep(i,n-1) cout << p[i] << " ";
  cout << p[n-1] << endl;
}
