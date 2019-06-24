#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
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

int main(){
#define int ll
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  int sum = SUM(a);
  int x = n * (n + 1) / 2;
  if(sum % x){
    cout << "NO\n";
    return 0;
  }
  int k = sum / x;
  vi d(n);
  rep(i,n) d[i] = a[(i+1)%n] - a[i] - k;
  x = 0;
  rep(i,n)
    if(d[i] > 0 or d[i] % n){
      cout << "NO\n";
      return 0;
    }else x -= d[i] / n;
  if(x == k) cout << "YES\n";
  else cout << "NO\n";
}
