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
  vi a(n);
  vi pos(n);
  rep(i,n){
    cin >> a[i]; a[i]--;
    pos[a[i]] = i;
  }

  set<int> st1,st2;
  // insert sentinels
  st1.insert(-1); st1.insert(n);
  st2.insert(1); st2.insert(-n);

  int res = 0;
  rep(ai,n){
    int r = *st1.lower_bound(pos[ai]);
    int l = -*st2.lower_bound(-pos[ai]);
    //cout << l << " " << r << endl;
    //cout << (pos[ai] - l) * (r - pos[ai]) << endl;
    res += (ai+1) * (pos[ai] - l) * (r - pos[ai]);
    st1.insert(pos[ai]);
    st2.insert(-pos[ai]);
  }
  cout << res << endl;
}
