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
  int m = s.size();
  rep(i,s.size()-1){
    if(s[i]!=s[i+1])
      m=min(m,max(i,(int)s.size()-i-1));
  }
  cout << m << endl;
}
