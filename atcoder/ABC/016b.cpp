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
  int a,b,c;
  cin >> a >> b >> c;
  if(!b && a==c) return cout << '?' << endl,0;
  if(c==a+b) cout << '+';
  else if(c==a-b) cout << '-';
  else cout << '!';
  cout << endl;
}
