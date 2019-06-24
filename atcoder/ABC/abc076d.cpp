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

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define int ll

struct func{
  int l,r,v;
};

main(){
  int n; cin >> n;
  vector<struct func> f(n+2);
  int t = 0; // T
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n){
    f[i].l = t;
    t += 2 * a[i]; // 0.5刻みで見るため2倍
    f[i].r = t;
    f[i].v = b[i];
  }
  // 最初の速度と最後の速度
  f[n].l = f[n].r = f[n].v = f[n+1].v = 0;
  f[n+1].l = f[n+1].r = t;
  //rep(i,n+2) cout << f[i].l << " " << f[i].r << " " << f[i].v << endl;

  double before = 0, now; // v(a), v(a + 0.5)
  double ans = 0;
  FOR(i,1,t+1){ // i : a
    now = inf;
    // v(a + 0.5)を求める
    rep(j,n+2){
      if(i < f[j].l){
	now = min(now, f[j].v + double(f[j].l - i) / 2); // 割る2は2倍した分
      }else if(f[j].r < i){
	now = min(now, f[j].v + double(i - f[j].r) / 2);
      }else{
	now = min(now, (double)f[j].v);
      }
    }
    //cout << double(i)/2 << "\t" << before << "\t" << now << endl;
    ans += (before + now) / 4;
    before = now;
  }
  printf("%.10f\n",ans);
}
