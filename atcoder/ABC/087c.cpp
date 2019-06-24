#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n; cin >> n;
  vii a(2);
  a[0].resize(n);
  a[1].resize(n);
  rep(i,n) cin >> a[0][i];
  rep(i,n) cin >> a[1][i];

  int max_v = 0;
  int c;
  rep(i,n){
    c = 0;
    rep(j,i+1) c += a[0][j];
    FOR(j,i,n) c += a[1][j];
    //cout << c << endl;
    max_v = max(c,max_v);
  }
  cout << max_v << endl;
}
