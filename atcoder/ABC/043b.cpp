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

#define mod 1000000007;

main(){
  string s; cin >> s;
  vector<char> ans;
  rep(i,s.size()){
    if(s[i] == 'B' && ans.size() != 0) ans.pop_back();
    else if(s[i] != 'B') ans.push_back(s[i]);
  }
  rep(i,ans.size()) cout << ans[i];
  cout << endl;
}
