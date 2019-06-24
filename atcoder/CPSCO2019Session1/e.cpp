#include <bits/stdc++.h>
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
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>void add(T &a, const T &b){a += b; a %= mod;}

signed main(){
  int n, q; cin >> n >> q;
  map<int,int> mp;
  int xx;
  rep(i,n){
    cin >> xx;
    mp[xx] ^= 1;
  }
  set<int> st;
  for(auto y : mp){
    if(y.second) st.insert(y.first);
  }

  rep(_,q){
    int l,r,x; cin >> l >> r >> x;
    int ans = 0, c = 0;
    auto last = st.end();
    for(auto itr = st.lower_bound(l); itr != st.end() and *itr <= r; ++itr){
      c ^= 1;
      ans ^= *itr;
      last = itr;
    }
    if(last != st.end()) ++last;
    else{ // l 以上r未満の要素がひとつもないとき
      cout << 0 << endl;
      continue;
    }
    st.erase(st.lower_bound(l),last);
    if(c and st.count(x) == 0) st.insert(x);
    else if(c and st.count(x) == 1) st.erase(x);
    cout << ans << endl;
    dump(st);
  }
}
