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

constexpr int inf = 1ll<<61;
constexpr int mod = 1e9+7;

main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];

  map<int,int> f,g;
  rep(i,n){
    if(i&1) f[a[i]]++;
    else g[a[i]]++;
  }
  pii x1=pii(-1,0),x2=pii(-1,0),y1=pii(-1,0),y2=pii(-1,0);
  for(auto x : f){
    if(x.second > x1.second){
      x2 = x1;
      x1 = x;
    }else if(x.second > x2.second){
      x2 = x;
    }
  }
  for(auto x : g){
    if(x.second > y1.second){
      y2 = y1;
      y1 = x;
    }else if(x.second > y2.second){
      y2 = x;
    }
  }
  dump(x1,x2,y1,y2);
  if(x1.first != y1.first){
    cout << n - x1.second - y1.second << endl;
    return 0;
  }else{
    if(x1.second + y2.second > x2.second + y1.second and x1.first != y2.second){
      cout << n - x1.second - y2.second << endl;
      return 0;
    }else if(x1.second + y2.second <= x2.second + y1.second and x2.first != y1.second){
      cout << n - x2.second - y1.second << endl;
      return 0;
    }
  }
  return 1;
}
