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
template <class BI>

bool next_partial_permutation(BI first, BI middle, BI last) {
  reverse(middle, last);
  return next_permutation(first, last);
}

int main(){
#define int ll
  int n,c; cin >> n >> c;
  vvi d(c,vi(c));
  rep(i,c) rep(j,c){
    cin >> d[i][j];
    d[i][j];
  }
  vvi mp(3,vi(c));
  FOR(i,1,n+1) FOR(j,1,n+1){
    int x; cin >> x;
    mp[(i+j)%3][x-1]++;
  }

  vi to(c);
  rep(i,c) to[i] = i;
  int ans = inf;
  do{
    int tmp = 0;
    rep(i,3) rep(j,c){
      tmp += mp[i][j] * d[j][to[i]];
    }
    ans = min(ans, tmp); 
  }while(next_partial_permutation(to.begin(),to.begin()+3,to.end()));
  cout << ans << endl;
}
