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
  while(1){
    int w,d; cin >> w >> d;
    if(w == 0) break;

    // 数を数える O(w + d)
    map<int,int> mph,mpd;
    rep(i,w){
      int h; cin >> h;
      mph[h]++;
    }
    rep(i,d){
      int h; cin >> h;
      mpd[h]++;
    }

    // 大きい方を足す O(w log d + d log w)
    int ans = 0;
    for(auto x : mph){
      auto y = mpd.find(x.fst);
      if(y == mpd.end()) ans += x.fst * x.snd;
      else ans += x.fst * max(x.snd, y->snd);
    }
    for(auto y : mpd){
      auto x = mph.find(y.fst);
      if(x == mph.end()) ans += y.fst * y.snd;
    }
    cout << ans << endl;
  }
}
