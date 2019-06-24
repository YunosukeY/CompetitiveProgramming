#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
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

#define int ll

main()
{
  vi year(1001),mon(11),three(11);
  rep(i,5){
    mon[2*i+1] = 20ll;
    mon[2*i+2] = 19ll;
    three[2*i+2] = three[2*i+1] = 20ll;
  }
  rep(i,9){
    mon[i+2] += mon[i+1];
    three[i+2] += three[i+1];
  }
  rep(i,1000){
    if(i % 3 == 2){
      year[i+1] += year[i] + three[10];
    }else
      year[i+1] += year[i] + mon[10];
  }
  int n; cin >> n;
  rep(i,n){
    int y,m,d; cin >> y >> m >> d; y--; m--;
    int x;
    if(y % 3 == 2) x = three[m];
    else x = mon[m];
    cout << year[1000] - (year[y] + x + d) - 194 << endl;
  }
}
