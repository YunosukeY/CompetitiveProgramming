#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using vi  = vector<int>;
constexpr ll inf = 1ll<<61;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

signed main(){
  int a,b,q; cin >> a >> b >> q;
  vi s(a+2), ms(a+2);
  rep(i,a){
    cin >> s[i];
    ms[i] = -s[i];
  }
  vi t(b+2), mt(b+2);
  rep(i,b){
    cin >> t[i];
    mt[i] = -t[i];
  }
  s[a] = t[b] = ms[a] = mt[b] = inf;
  s[a+1] = t[b+1] = ms[a+1] = mt[b+1] = -inf;
  sort(all(s));
  sort(all(t));
  sort(all(ms));
  sort(all(mt));

  rep(k,q){
    int x; cin >> x;
    
    int la = -*lower_bound(all(ms),-x);
    int lb = -*lower_bound(all(mt),-x);
    int ra = *lower_bound(all(s),x);
    int rb = *lower_bound(all(t),x);

    int res = inf;
    chmin(res, abs(x - la) + abs(-*lower_bound(all(mt),-la) - la));
    chmin(res, abs(x - la) + abs(*lower_bound(all(t),la) - la));

    chmin(res, abs(x - lb) + abs(-*lower_bound(all(ms),-lb) - lb));
    chmin(res, abs(x - lb) + abs(*lower_bound(all(s),lb) - lb));

    chmin(res, abs(x - ra) + abs(-*lower_bound(all(mt),-ra) - ra));
    chmin(res, abs(x - ra) + abs(*lower_bound(all(t),ra) - ra));
    
    chmin(res, abs(x - rb) + abs(-*lower_bound(all(ms),-rb) - rb));
    chmin(res, abs(x - rb) + abs(*lower_bound(all(s),rb) - rb));

    cout << res << endl;
  }
}
