#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);


int main(){
  int i,j;
  int n,k;
  cin >> n >> k;
  vector<double> r(n);
  rep(i,n)
    cin >> r[i];

  sort(all(r));
  //rep(i,n) cout << r[i] << " ";
  //cout << endl;

  double ans=0;
  For(i,n-k,n)
    ans=(ans+r[i])/2;

  cout << setprecision(20) << ans << endl;
  return 0;
}
