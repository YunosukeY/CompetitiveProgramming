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

int m, k;
int x, l;
void rec(vi a, int i){
  if(i == l){
    map<int,set<int>> mp;
    rep(j,l) mp[a[j]].insert(j);
    bool f = true;
    for(auto p : mp){
      if(p.second.size() != 2) f = false;
    }
    if(f){
      bool g = true;
      for(auto p : mp){
	int b = -1, c;
	for(auto ss : p.second){
	  if(b == -1) b = ss;
	  else c = ss;
	}
	int tmp = 0;
	FOR(j,b,c+1) tmp^=a[j];
	if(tmp != k) g = false;
      }
      if(g){
	dump(a);
      }
    }
  }else{
    rep(j,x){
      a[i] = j;
      rec(a,i+1);
    }
  }
}

template<typename T>
T mypow(T a, ll n){
  bool f = (n < 0);
  n = abs(n);
  
  T ans(1);
  while(n){
    if(n&1) ans *= a;
    a *= a;
    n = n >> 1;
  }

  if(f) ans = T(1) / ans;
  return ans;
}

signed main(){
  cin >> m >> k;
  x = mypow(2ll,m); l = mypow(2ll,m+1);
  // vi a(l);
  //rec(a,0);
  if(k == 0){
    rep(i,l){
      if(i == 0) cout << i;
      else cout << " " << i/2;
    }
    cout << endl;
  }else if(x <= k or (m == 1 and k == 1)){
    cout << -1 << endl;
  }else{
    rep(i,x){
      if(i != k) cout << i << " ";
    }
    cout << k << " ";
    ROF(i,x,0){
      if(i != k) cout << i << " ";
    }
    cout << k << endl;
  }
}
