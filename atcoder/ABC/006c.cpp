#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;  

int main(){
  int i,j;
  int n,m;
  int a,b,c;
  cin >> n >> m;
  c=(m-2*n)/2;
  a=n-c;
  if(a>=0 && c>=0 && 2*a+4*c==m){
    return cout << a << " 0  " << c << endl,0;
  }
  m-=3;
  c=(m-2*n)/2;
  a=n-c-1;
  if(a>=0 && c>=0 && 2*a+4*c==m){
    return cout << a << " 1 " << c << endl,0;
  }
  return cout << "-1 -1 -1" << endl,0;
}

