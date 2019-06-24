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
  int i;
  string s;
  int t;
  cin >> s >> t;
  int numq=0;
  pii pt; pt.first=0; pt.second=0;
  rep(i,s.size()){
    if(s[i]=='L') pt.first--;
    else if(s[i]=='R') pt.first++;
    else if(s[i]=='U') pt.second++;
    else if(s[i]=='D') pt.second--;
    else numq++;
  }
  int ans=abs(pt.first)+abs(pt.second);
  if(t==1) cout << ans+numq;
  else
    if(ans<numq)
      if((numq-ans)%2==0) cout << 0;
      else cout << 1;
    else cout << ans-numq;
  cout << endl;
}
