w#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int a,b; cin >> a >> b;
  string s; cin >> s;
  rep(i,s.size()){
    if(i < a && '0' <= s[i] && s[i] <= '9') continue;
    else if(i == a && s[i] == '-') continue;
    else if(a < i && '0' <= s[i] && s[i] <= '9') continue;
    else{
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
