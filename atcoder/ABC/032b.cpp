#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
typedef vector<int> vi;
typedef vector< vi > vii;

main(){
  int l,h,n;
  cin >> l >> h >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    if(a[i]<l) cout << l-a[i];
    else if(h<a[i]) cout << -1;
    else cout << 0;
    cout << endl;
  }
}
