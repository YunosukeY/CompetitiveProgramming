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

constexpr int inf = 1ll<<62;
constexpr int mod = 1e9+7;

main(){
  int n,m,a,b; cin >> n >> m >> a >> b;
  vi x(n,b);
  rep(i,m){
    int l,r; cin >> l >> r; l--; r--;
    FOR(j,l,r+1) x[j] = a;
  }
  dump(x);
  cout << accumulate(all(x),0ll) << endl;
}
