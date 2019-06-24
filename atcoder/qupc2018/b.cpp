#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<ll>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<ll,ll>;

constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;

main(){
  int q; cin >> q;
  rep(k,q){
    int a,b,c; cin >> a >> b >> c;
    int sum = 100*a+10*b+c;
    if(sum&1){
      cout << "No\n";
      continue;
    }
    int half = sum/2;
    if(half > a*100) half -= a*100;
    else half %= 100;
    if(half > b*10) half -= b*10;
    else half %= 10;
    if(half > c) half -= c;
    else half %= 1;
    if(half) cout << "No\n";
    else cout << "Yes\n";
  }
    
}
