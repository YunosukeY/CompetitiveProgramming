#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
typedef vector<int> vi;
typedef vector< vi > vii;

int main(){
  int i,j;
  int sum=2025;
  int n;
  cin >> n;
  n=sum-n;
  FOR(i,1,10){
    if(n%i==0 && n/i<=9)
      cout << i << " x " << n/i << endl;
  }
  return 0;
}
