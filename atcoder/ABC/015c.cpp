#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);

int n,k;
vector< vector<int> > t;

bool dfs(int d,int x){//バグならtrue
  if(d==n) return x==0;

  int j;
  rep(j,k){
    if(dfs(d+1,x^t[d][j]))//dより下でバグ
      return true;
  }
  return false;
}

int main(){
  int i,j;
  cin >> n >> k;
  t.resize(n,vector<int>(k));
  rep(i,n)
    rep(j,k)
    cin >> t[i][j];

  if(dfs(0,0)) cout << "Found";
  else cout << "Nothing";
  cout << endl;
  
  return 0;
}
