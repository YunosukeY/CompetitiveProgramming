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
  int n,k; cin >> n >> k;
  vi l(n); rep(i,n) cin >> l[i];
  sort(l.rbegin(),l.rend());
  int ans=0;
  rep(i,k) ans+=l[i];
  cout << ans << endl;
}
