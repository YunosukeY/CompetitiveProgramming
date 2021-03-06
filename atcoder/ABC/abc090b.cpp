#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

bool judge(int n){
  string s = to_string(n);
  rep(i,s.size()/2) if(s[i] != s[s.size()-i-1]) return false;
  return true;
}

main(){
  int a, b; cin >> a >> b;
  int ans = 0;
  FOR(i,a,b+1) if(judge(i)) ans++;
  cout << ans << endl;
}
