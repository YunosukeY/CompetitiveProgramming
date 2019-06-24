#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);

int main(){
  int i,j,n,t;
  cin >> n >> t;
  vector<int> a(n+1,0);
  For(i,1,n+1) scanf("%d",&a[i]);
  
  vector<int> c(a[n]+1,0);
  For(i,1,n+1) c[a[i]]=t;
  /*
  rep(i,a[n]) cout << c[i] << " ";
  cout << endl;
  */
  j=1;
  For(i,1,a[n]){
    if(i==a[j] && j<=n) j++;
    else if(i!=a[j]) c[i]=max(c[i-1]-1,0);
  }
  ll ans=0;
  rep(i,a[n])
    if(c[i]>0) ans++;
  ans+=t;
  /*
  rep(i,a[n]) cout << c[i] << " ";
  cout << endl;
  */
  cout << ans << endl;  

  return 0;
}
