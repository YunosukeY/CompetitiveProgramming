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
  int k,s; cin >> k >> s;
  int ans = 0;
  int z;
  rep(i,k+1) rep(j,k+1){
    z = s - i - j;
    if(0 <= z && z <= k) ans++;
  }
  cout << ans << endl;
}
