#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);

int main(){
  int i;
  vector<int> a(5);
  rep(i,5) cin >> a[i];

  sort(all(a));

  cout << max(a[4]+a[3]+a[0],a[4]+a[2]+a[1]) << endl;
	
  return 0;
}
