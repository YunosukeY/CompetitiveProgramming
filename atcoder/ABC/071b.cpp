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
  vi a(26);
  rep(i,s.size()) a[s[i]-'a']++;
  rep(i,26)
    if(!a[i]){
      cout << (char)(i+'a') << endl;
      return 0;
    }
  cout << "None\n";
    
}
