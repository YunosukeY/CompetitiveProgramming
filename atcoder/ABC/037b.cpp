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
  int n; cin >> n;
  vi a(n,0);
  int q; cin >> q;
  int l,r,t;
  rep(i,q){
    cin >> l >> r >> t;
    fill(a.begin()+l-1,a.begin()+r,t);
    //rep(i,n) cout << a[i] << endl;
  }
  rep(i,n) cout << a[i] << endl;
}
