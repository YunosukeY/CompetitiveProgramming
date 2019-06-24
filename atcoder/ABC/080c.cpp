#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n; cin >> n;
  vector<bitset<10>> f(n);
  rep(i,n) rep(j,10){
    int a; cin >> a;
    if(a) f[i].set(9-j);
    else f[i].reset(9-j);
  }
  vii p(n,vi(11));
  rep(i,n) rep(j,11) cin >> p[i][j];

  int ans = -1 * (1<<30);
  FOR(b,1,1024){
    bitset<10> bs(b);
    int c = 0;
    rep(i,n){
      int ci = (bs & f[i]).count();
      c += p[i][ci];
    }
    ans = max(ans,c);
    //cout << bs << endl << c << endl;
  }
  /*
  rep(i,n){
    rep(j,10) cout << f[i][j];
    cout << endl;
  }
  */
  cout << ans << endl;
}
