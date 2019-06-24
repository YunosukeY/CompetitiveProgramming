#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

main(){
  int n,m; cin >> n >> m;
  vs a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  rep(i,n-m+1) rep(j,n-m+1) rep(k,m){
    if(b[k] != a[i+k].substr(j,m)) break;
    if(k==m-1){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
