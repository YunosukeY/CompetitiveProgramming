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
  vi a(n+1),b(n);
  rep(i,n) b[i] = i;

  do{
    dump(b);
    vi c(n,1);
    rep(i,n){
      int l = 0, r = n-1;
      FOR(j,b[i],n)
	if(c[j]) continue;
	else{
	  r = j-1;
	  break;
	}
      ROF(j,b[i]+1,0)
	if(c[j]) continue;
	else{
	  l = j+1;
	  break;
	}
      c[b[i]] = 0;
      a[l]++;
      a[r+1]--;
    }
  }while(next_permutation(all(b)));
  rep(i,n) a[i+1] += a[i];
  dump(a);
}
