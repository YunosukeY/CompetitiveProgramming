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
typedef long long ll;
#define inf 100
main(){
  int n; cin >> n;
  vii d(n);
  rep(i,n){
    d[i].resize(n);
    rep(j,n) d[i][j] = inf;
  }
  int m; cin >> m;
  rep(i,m){
    int a,b; cin >> a >> b;
    d[a-1][b-1] = 1; d[b-1][a-1] = 1;
  }
  rep(k,n) rep(i,n) rep(j,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
  rep(i,n) d[i][i] = 0;
  rep(i,n){
    int count = 0;
    rep(j,n) if(d[i][j] == 2) count++;
    cout << count << endl;
  }
}
