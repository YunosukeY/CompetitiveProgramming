#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);


int main(){
  ll n,Y; cin >> n >> Y;
  ll x,y,z;
  rep(i,(Y/10000)+1){
    x = i;
    y = (Y -(1000*n) - (9000*x))/4000;
    z = n - x - y;
    //cout << x << " " << y << " " << z << endl;
    if(y >= 0 and z >= 0 and 10000*x+5000*y+1000*z == Y){
      cout << x << " " << y << " " << z << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1\n";
}
