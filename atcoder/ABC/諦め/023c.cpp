#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);
#define size 100000

int r[size],c[size];
int x[size],y[size];
int a[size+10],b[size+10];

int main(){
  int i,j;
  int R,C,k,n;
  cin >> R >> C >> k >> n;
  rep(i,n){
    //cin >> r[i] >> c[i];
    scanf("%d %d",&r[i],&c[i]);
    x[--r[i]]++;
    y[--c[i]]++;
  }
  /*
  For(i,1,n+1) cout << x[i] << " ";
  cout << endl;
  For(i,1,n+1) cout << y[i] << " ";
  cout << endl;
  */
  rep(i,C)
    a[x[i]]++;
  rep(i,R)
    b[y[i]]++;
  /*
  rep(i,n) cout << a[i] << " ";
  cout << endl;
  rep(i,n) cout << b[i] << " ";
  cout << endl;
  */
  ll ans=0;
  rep(i,k)
    ans+=(ll) (a[i]*b[k-i]);
  rep(i,n){
    j=x[r[i]]+y[c[i]];
    if(j==k) ans--;
    else if(j==k+1) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
