#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;

int main(){
  int i,j;
  int n;
  vi a;
  int min;
  while(1){
    cin >> n;
    if(n==0) break;
    a.resize(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    min=10000000;
    j=0;
    rep(i,n-1)
      if(a[i+1]-a[i]<min){
	min=a[i+1]-a[i];
      }
    cout << min << endl;
  }
  
  return 0;
}
