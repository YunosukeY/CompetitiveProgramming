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
  string s;
  cin >> s;
  int i;
  vi nim(6);
  rep(i,s.size()){
    if(s[i]=='A') nim[0]++;
    else if(s[i]=='B') nim[1]++;
    else if(s[i]=='C') nim[2]++;
    else if(s[i]=='D') nim[3]++;
    else if(s[i]=='E') nim[4]++;
    else if(s[i]=='F') nim[5]++;
  }
  rep(i,5) cout << nim[i] << " ";
  cout << nim[5] << endl;
}
