#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

template < typename T > string to_string(T& n){
  ostringstream stm ;
  stm << n ;
  return stm.str() ;
}

main(){
  double n,m;
  cin >> n >> m;
  if(n>=12) n=n-12;
  n=30*n+m/2;
  m*=6;
  double ans=fabs(n-m);
  if(ans>180) ans=360-ans;
  //cout << n << " " << m << endl;
  cout << ans << endl;
}
