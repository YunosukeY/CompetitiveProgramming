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
  vi a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  vi c(m),d(m); rep(i,m) cin >> c[i] >> d[i];

  long long min,p;
  rep(i,n){
    min = 1000000000;
    rep(j,m){
      if(abs(a[i]-c[j])+abs(b[i]-d[j])<min){
	min = abs(a[i]-c[j])+abs(b[i]-d[j]);
	p = j;
      }
    }
    cout << p+1 << endl;
  }
}
