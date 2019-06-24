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
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  int sum=accumulate(all(a),0);
  int av=sum/a.size();
  if(av*a.size()!=sum) return cout << -1 << endl,0;
  int c=0;
  sum=0;
  rep(i,n){
    sum+=a[i];
    if(sum!=av*(i+1)) c++;
  }
  cout << c << endl;
}
