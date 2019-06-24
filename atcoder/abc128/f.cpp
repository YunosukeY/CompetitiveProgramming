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
vi s;

int test(int a, int b){
  int now = 0;
  int ans = 0;
  vi use(n);
  use[0] = 1;
  while(1){
    now += a;
    if(now >= n) return -inf;
    if(use[now] == 1) return -inf;
    use[now] = 1;
    ans += s[now];
    if(now == n-1) break;
    now -= b;
    if(use[now] == 1) return -inf;
    ans += s[now];
    use[now] = 1;
  }
  return ans;
}
    
signed main(){
  cin >> n;
  s.resize(n); rep(i,n) cin >> s[i];
  int ans = 0;
  FOR(i,1,n) FOR(j,1,i){
    if(chmax(ans, test(i,j))){
      dump(i,j);
    }
  }
  cout << ans << endl;
  // int ans = 0;
  // FOR(a,n/2,n){
  //   int b = 2*a - (n-1);
  //   if(a <= b or b <= 0) continue;
  //   dump(a,b);
  //   int tmp = 0;
  //   FOR(i,a,n) tmp += s[i];
  //   rep(i,n-a) tmp += s[i];
  //   chmax(ans,tmp);
  // }
  // cout << ans << endl;
}
