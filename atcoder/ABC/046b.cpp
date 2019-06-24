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
  int n,k; cin >> n >> k;
  long long ans = 1;
  rep(i,n)
    if(i == 0) ans *= k;
    else ans *= k-1;
  cout << ans << endl;
}
