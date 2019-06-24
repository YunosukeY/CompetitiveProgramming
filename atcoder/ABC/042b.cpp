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
  int n, l; cin >> n >> l;
  vs s(n); rep(i,n) cin >> s[i];
  sort(all(s));
  string ans;
  rep(i,n) ans += s[i];
  cout << ans << endl;
}
