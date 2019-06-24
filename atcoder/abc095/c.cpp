#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;


#define int ll

const int inf = 1ll<<62;
const int mod = 1e9+7;

main(){
  int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  int z = min(x,y); x -= z; y -= z;
  int ans = z * min(a + b, 2 * c);
  if(x > 0){
    ans += x * min(a, 2 * c);
  }else if(y > 0){
    ans += y * min(b, 2 * c);
  }
  cout << ans << endl;
}
