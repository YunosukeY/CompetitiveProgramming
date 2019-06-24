#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;

int main(){
  int i,j;
  int n,a,b,m;
  cin >> n >> a >> b >> m;
  vi x(m),y(m),looked(n,0);
  vector< vector<int> > ad(n);
  rep(i,n) ad[i].resize(n);
  rep(i,m){
    cin >> x[i] >> y[i];
    ad[x[i]][y[i]]=1;
    ad[y[i]][x[i]]=1;
  }
  rep(i,n){
    rep(j,n)
      cout << ad[i][j] << " ";
    cout << endl;
  }
  
  return 0;
}
