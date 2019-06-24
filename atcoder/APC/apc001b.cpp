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
  vi b(n); rep(i,n) cin >> b[i];
  int k = SUM(b) - SUM(a);
  if(k < 0){
    cout << "No\n";
    return 0;
  }

  int ca = 0, cb = 0;
  rep(i,n){
    if(a[i] >= b[i]) cb += a[i] - b[i];
    else{
      ca += (b[i] - a[i] + 1) / 2;
      cb += (b[i] - a[i]) & 1;
    }
  }
  //cout << (k - ca) << endl << (k - cb) << endl;
  if(ca <= k and cb <= k) cout << "Yes\n";
  else cout << "No\n";
}
