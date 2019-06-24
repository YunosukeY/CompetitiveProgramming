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
  int n,k; cin >> n >> k;
  int len = 3*k,w = 2*k;
  vii a(len,vi(len,0));
  rep(i,n){
    int x,y; char c; cin >> x >> y >> c;
    if(c == 'W') y += k;
    y += k-1;
    x %= w;
    y %= w;
    
    
    cout << x << y << endl;
    //imosの準備
    a[x][y-k+1]++;
    a[x][y+1]--;
    a[x+k][y-k+1]--;
    a[x+k][y+1]++;
  }
  //imos
  rep(i,len) FOR(j,1,len) a[i][j] += a[i][j-1];
  rep(j,len) FOR(i,1,len) a[i][j] += a[i-1][j];

  //rep(i,w) rep(j,k) a[i][j+w] += a[i][j];
  //FOR(i,w,len) FOR(j,k,len) a[i-w][j] += a[i][j];
  //FOR(i,w,len) rep(j,k) a[i-w][j+w] += a[i][j];
  rep(i,len){
    rep(j,len) cout << a[i][j];
    cout << endl;
  }
}
