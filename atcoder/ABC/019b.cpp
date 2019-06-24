#include<bits/stdc++.h>
#include<string>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

template < typename T > string tos(T& n){
  ostringstream stm ;
  stm << n ;
  return stm.str() ;
}

main(){
  string s,ans;
  char buf;
  cin >> s;;
  buf=s[0];
  int c=1;
  FOR(i,1,s.size()){
    if(buf==s[i]) c++;
    else{
      ans+=buf + tos(c);
      c=1;
      buf=s[i];
    }
    if(i==s.size()-1) ans+=buf + tos(c);
  }
  
  cout << ans << endl;
}
