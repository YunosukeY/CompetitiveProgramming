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
  int i,j;
  int n,a,b;
  cin >> n >> a >> b;
  int total=0;
  string s;
  int d;
  rep(i,n){
    cin >> s >> d;
    if(d<a) d=a;
    else if(b<d) d=b;
    if(s=="West") d*=-1;
    total+=d;
  }
  if(0<total) cout << "East " << total;
  else if(total<0) cout << "West " << -1*total;
  else cout << 0;
  cout << endl;
}
