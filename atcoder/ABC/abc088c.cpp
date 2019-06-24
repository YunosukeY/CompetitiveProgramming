#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector<vi> vvi;

main(){
  vvi c(3,vi(3));
  rep(i,3) rep(j,3) cin >> c[i][j];

  rep(i,2) rep(j,2)
    if(c[i][j] - c[i][j+1] != c[i+1][j] - c[i+1][j+1]){
      cout << "No\n";
      return 0;
    }

  cout << "Yes\n";
}
