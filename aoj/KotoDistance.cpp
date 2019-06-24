#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
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

main()
{
  int n,w,h; cin >> n >> w >> h;
  vi a(w+1), b(h+1);

  rep(i,n){
    int x,y,c; cin >> x >> y >> c;
    a[max(0ll,x-c)]++;
    a[min(w,x+c)]--;
    b[max(0ll,y-c)]++;
    b[min(h,y+c)]--;
  }
  bool ansx = true, ansy = true;
  rep(i,w){
    if(a[i] == 0) ansx = false;
    a[i+1] += a[i];
  }
  rep(i,h){
    if(b[i] == 0) ansy = false;
    b[i+1] += b[i];
  }
  if(ansx or ansy) cout << "Yes\n";
  else cout << "No\n";
  dump(a,b);
}
