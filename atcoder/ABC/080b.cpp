#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
typedef vector<int> vi;
typedef vector< vi > vii;

main(){
  string n;
  cin >> n;
  int fn=0;
  rep(i,n.size()) fn+=stoi(n[i]);
  if(stoi(n)%fn==0) cout << "Yes";
  else cout << "No";
  cout << endl;
}
