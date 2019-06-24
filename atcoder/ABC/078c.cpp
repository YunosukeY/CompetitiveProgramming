#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define SUM(a) accumulate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n; cin >> n;
  ll x,X,m;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
    X += a[i];
  }
  x = a[0]; m = abs(X-2*x);
  cout << x << " " << " " << m << endl;
  FOR(i,1,n-1){
    x += a[i]; m = min(m,abs(X-2*x));
    cout << x << " " << m << endl;
  }
  cout << m << endl;
}
