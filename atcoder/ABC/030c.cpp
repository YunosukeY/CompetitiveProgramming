#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);

int main(){
  int i,j;
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<int> a(n+1,0),b(m+1,0);
  rep(i,n) scanf("%d",&a[i+1]);
  rep(i,m) scanf("%d",&b[i+1]);
  int ap=0,time=0;
  int ans=0;
  //cout << a[n] << " " << b[m] << endl;
  while(1){
    if(ap==0){//ap a
      if(time>a[n]) break;
      i=distance(a.begin(),lower_bound(a.begin()+1,a.end(),time));
      time=a[i]+x;
      ap=1;
    }else{
      //cout << time << endl;      
      if(time>b[m]) break;
      i=distance(b.begin(),lower_bound(b.begin()+1,b.end(),time));
      time=b[i]+y;
      ap=0;
      ans++;
    }
  }

  cout << ans << endl;
   
  
}
