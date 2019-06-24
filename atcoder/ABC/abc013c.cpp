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

#define int ll

main(){
  int n,h,a,b,c,d,e; cin >> n >> h >> a >> b >> c >> d >> e;

  int ans = 1 << 29;

  rep(x,n+1){
    int y = max((int)ceil((n-x)*e-h-b*x)/(d+e)+1,(int)0);
    if(x + y <= n) ans = min(ans,a*x+c*y);
    cout << x << " " << y << " " << ans << endl;
  }

  cout << ans << endl;
}
