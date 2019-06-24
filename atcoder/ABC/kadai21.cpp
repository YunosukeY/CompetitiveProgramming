#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;


int main(){
  int i,j;
  int m,nmin,nmax;
  cin >> m >> nmin >> nmax;
  vi p(m);
  rep(i,m)
    cin >> p[i];

  sort(p.begin(),p.end());
  /*
  rep(i,m)
    cout << p[i] << " ";
  cout << endl;
  */
  int n,divmax=0,div;
  For(i,nmin,nmax+1){
    div=p[m-i]-p[m-i-1];
    //cout << div << endl;
    if(div>=divmax){
      divmax=div;
      n=i;
    }
  }
  cout << n << endl;
  return 0;
}
