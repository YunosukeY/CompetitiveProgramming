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

int n;
vector<pii> a;

map<int,int> pf(int m){
  map<int,int> res;
  FOR(i,2,sqrt(m)+1){
    if(m == 1) break;
    while(m%i == 0){
      res[i]++;
      m /= i;
    }
  }
  if(m != 1) res[m]++;
  return res;
}

int rec(vector<pii> &b, int j){
  if(j == sz(b)){
    dump(b);
    int m = 1;
    rep(k,sz(b)) rep(x,b[k].snd) m *= b[k].fst;
    if(n % m == 0 and n/m < m-1){
      return m-1;
    }else return 0;
  }

  int tmp = 0;
  b[j].fst = a[j].fst;
  int nextj = j+1;
  rep(k,a[j].snd+1){
    b[j].snd = k;
    tmp += rec(b, nextj);
  }
  return tmp;
}

signed main(){
  cin >> n;
  map<int,int> f = pf(n);
  for(auto x : f)
    a.pb(x);
  
  vector<pii> init(sz(a));
  int i = 0;
  int ans = rec(init, i);
  //cout << ans + (n-1) << endl;
  cout << ans << endl;
}
