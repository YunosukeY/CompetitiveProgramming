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


int dx[9] = {0, 1, 0, -1, 0, 1, -1, -1, 1}, dy[9] = {0, 1, 0, -1, 1, 1, -1, -1};

main(){
  ll n,m; cin >> n >> m;
  
  ll ans = 0;
  if(n == 1 and m == 1) ans = 1;
  else if(n == 2 or m == 2) ans = 0;
  else if(n == 1) ans = m - 2;
  else if(m == 1) ans = n - 2;
  else ans = (m -2 ) * (n -2);
  cout << ans << endl;
}
