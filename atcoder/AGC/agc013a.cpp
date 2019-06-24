#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

#define int ll

const int inf = 1ll<<62;
const int mod = 1e9+7;

main(){
  int n; cin >> n;
  vi x(n); rep(i, n) cin >> x[i];
  // 同じ要素が並ばないようにする
  vi a; a.pb(x[0]);
  rep(i, n - 1) if(x[i + 1] != x[i]) a.pb(x[i + 1]);
  dump(a);
  
  int ans = 1, now = 1, before;
  int c = 1;
  rep(i, sz(a) - 1){
    if(a[i] > a[i + 1]) now = 0;
    if(a[i] < a[i + 1]) now = 1;
    if(i == 0) before = now;
    dump(i+1,before, now,c);
    if(before != now and c > 1){
      //cout << i + 1 << endl;
      ans++;
      c = 1;
    }else c++;
    before = now;
  }
  dump(c);
  cout << ans << endl;
}
