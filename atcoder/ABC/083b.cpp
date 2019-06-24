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

int digitsum(ll n){
  int ans = 0;
  while(1){
    ans += n % 10;
    if(n < 10) break;
    n /= 10;
  }
  return ans;
}

main(){
  int n,a,b; cin >> n >> a >> b;
  int sum;
  int ans=0;
  FOR(i,1,n+1){
    sum=digitsum(i);
    if(a<=sum && sum<=b) ans+=i;
  }
  cout << ans << endl;
}
