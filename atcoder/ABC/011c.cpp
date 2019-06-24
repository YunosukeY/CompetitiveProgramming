#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);

int main(){
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  vector<int> dp(n+1,1000);
  dp[n]=0;
  int i,j;
  /*
  rep(i,n+1) cout << dp[i] << " ";
  cout << endl;
  */
  for(i=n;i>=0;i--){
    if(i==a || i==b || i==c) continue;
    For(j,1,min(4,i+1))
      dp[i-j]=min(dp[i]+1,dp[i-j]);
    /*
    rep(j,n+1) cout << dp[i] << " ";
    cout << endl;
    */
  }
  if(dp[0]<=100) cout << "YES";
  else cout << "NO";
  cout << endl;
  
  return 0;
}
