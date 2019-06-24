#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

main(){
  int n; cin >> n;
  vi t(n); rep(i,n) cin >> t[i];
  int sum = accumulate(all(t),0);
  int m; cin >> m;
  int p,x;
  rep(i,m){
    cin >> p >> x;
    cout << sum - (t[p-1] - x) << endl;
  }
}
