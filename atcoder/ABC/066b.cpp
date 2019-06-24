#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  string s; cin >> s;

  ROF(i,s.size()/2 - 1,0)
    if(s.substr(0,i) + s.substr(0,i) == s.substr(0,2*i)){
      cout << s.substr(1,2*i).size() << endl;
      break;
    }
}
