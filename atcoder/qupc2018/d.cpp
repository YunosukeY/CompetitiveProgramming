#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;

constexpr ll inf = 1ll<<60;
constexpr ll mod = 1e9+7;

main(){
  int n,m,l; cin >> n >> m >> l;
  vi t(n); rep(i,n) cin >> t[i];
  vvi a(n);
  rep(i,m){
    int x,y; cin >> x >> y; x--;
    a[x].pb(y);
  }
  vvi b(n);
  rep(i,l){
    int x,y; cin >> x >> y; x--;
    b[x].pb(y);
  }
  rep(i,n){
    sort(all(a[i]));
    a[i].pb(inf);
    sort(all(b[i]));
    b[i].pb(inf<<1);
  }

  int T = 0;
  int sum = 0;
  while(1){ // 時刻t以降にに王都を出発し、できるだけ早く戻ってくる仕事を探す
    int minv = inf;

    rep(i,n){
      // まず各都市について1番早く行ける仕事を探す
      int tmpa = *lower_bound(all(a[i]),T);
      tmpa += t[i] + 1;
      // 逆に1番早く帰れる仕事を探す
      int tmpb = *lower_bound(all(b[i]),tmpa);
      tmpb += t[i] + 1;
      minv = min(minv, tmpb);
    }
    
    if(minv == inf) break; // 仕事がない

    sum += 2;
    T = minv;
  }

  // 最後にどこかの都市に片道行けないか試す
  int minv = inf;
  rep(i,n){
    int tmp = *lower_bound(all(a[i]),T);
    minv = min(minv, tmp);
  }
  if(minv != inf) sum++;

  cout << sum << endl;

  return 0;
}
