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
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

signed main(){
  int n; cin >> n;
  vi a(3), b(3);
  rep(i,3) cin >> a[i];
  rep(i,3) cin >> b[i];
  rep(_,2){
    int m = n;
    vi c, d;
    rep(i,3) if(a[i] < b[i]){
      c.push_back(a[i]);
      d.push_back(b[i]);
    }
    if(c.size() == 3){
      rep(i,n+1) rep(j,n-i+1){
	int k = n - i - j;
	// 金にi,銀にj,銅にk個使う
	int x = i/c[0], y = j/c[1], z = k/c[2];
	int tmpn = n - x*c[0] - y*c[1] - z*c[2];
	tmpn += x*d[0] + y*d[1] + z*d[2];
	m = max(m, tmpn);
      }
    }else if(c.size() == 2){
      rep(i,n+1){
	int j = n - i;
	// 金にi,銀にj個使う
	int x = i/c[0], y = j/c[1];
	int tmpn = n - x*c[0] - y*c[1];
	tmpn += x*d[0] + y*d[1];
	m = max(m, tmpn);
      }
    }else if(c.size() == 1){
      int i = n;
      // 金にi個使う
      int x = i/c[0];
      int tmpn = n - x*c[0];
      tmpn += x*d[0];
      m = max(m, tmpn);
    }
    swap(a,b);
    n = m;
  }
  cout << n << endl;
}
