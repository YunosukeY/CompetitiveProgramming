#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;  

int main(){
  int i,j;
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  c=c-a;
  e=e-a;
  d=d-b;
  f=f-b;
  double ans=(double)(c*f-d*e);
  ans=fabs(ans)/2;
  cout << setprecision(20) << ans << endl;
  return 0;
}
