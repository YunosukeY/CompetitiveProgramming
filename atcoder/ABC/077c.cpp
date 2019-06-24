#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n; cin >> n;
  vi a(n);
  int h = (n-1)/2,t = (n+1)/2;
  rep(i,n){
    if(i%2 == 0){
      cin >> a[h];
      h--;
    }else{
      cin >> a[t];
      t++;
    }
  }
  if(n%2 == 1){
    rep(i,n-1) cout << a[i] << " ";
    cout << a[n-1] << endl;
  }else{
    ROF(i,n,1) cout << a[i] << " ";
    cout << a[0] << endl;
  }
}
  
