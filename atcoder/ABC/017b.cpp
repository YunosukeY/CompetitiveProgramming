#include<bits/stdc++.h>
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

main(){
  string s;
  cin >> s;
  int flag=0;
  while(s.size()!=0){
    if(s.size()>1 && s.substr(s.size()-2,2)=="ch") s=s.substr(0,s.size()-2);
    else if(s.substr(s.size()-1,1)=="o") s=s.substr(0,s.size()-1);
    else if(s.substr(s.size()-1,1)=="k") s=s.substr(0,s.size()-1);
    else if(s.substr(s.size()-1,1)=="u") s=s.substr(0,s.size()-1);
    else{
      flag=1;
      break;
    }
  }
  if(flag) cout << "NO";
  else cout << "YES";
  cout << endl;
}
