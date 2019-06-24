#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;  

int main(){
  int i,j;
  int t,n,m;
  cin >> t >> n;
  vi takotime(n);
  rep(i,n) cin >> takotime[i];
  cin >> m;
  vi b(m);
  rep(i,m) cin >> b[i];
  vi tako(n,1);
  rep(i,m-1){
    j=distance(takotime.begin(),lower_bound(takotime.begin(),takotime.end(),b[i]-t));
    while(tako
    takotime[j]=-t;
    tako[j]--;
  }
  /*
  rep(i,n) cout << tako[i] << " ";
  cout << endl;
  */
  rep(i,n-1)
    if(tako[i]<0)
      return cout << "no" << endl,0;
  
  if(tako[n-1]==0) return cout << "no" << endl,0;
  for(i=n-1;i>=0;i--){
    if(b[m-1]-t <= takotime[i] && takotime[i]<=b[m-1] && tako[i]==1)
      return cout << "yes" << endl,0;
  }
  return cout << "no" << endl,0;
  
  return 0;
}
