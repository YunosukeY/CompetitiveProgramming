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
  int n; cin >> n;
  int m = n / 100;
  n %= 100;
  
  if(m > 0 and m <= 12 and 1 <= n and n <= 12){
    cout << "AMBIGUOUS\n";
  }else if(m > 0 and m <= 12){
    cout << "MMYY\n";
  }else if(1 <= n and n <= 12){
    cout << "YYMM\n";
  }else{
    cout << "NA\n";
  }
}

