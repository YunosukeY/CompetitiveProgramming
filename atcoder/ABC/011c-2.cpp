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
  int i,j,k;
  if(n==a||n==b||n==c) return printf("NO\n"),0;
  rep(i,100){
    for(j=3;j>0;j--)
      if(n-j!=a&&n-j!=b&&n-j!=c){
	n=n-j;
	break;
      }
  }
  if(n<=0) cout << "YES";
  else cout << "NO";
  cout << endl;
	
  return 0;
}
