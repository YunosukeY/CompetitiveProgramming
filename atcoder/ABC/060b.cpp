#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int gcd(int m,int n){
  if(m == 0 || n == 0) return 0;

  while(m != n){
    if(m > n) m -= n;
    else n -= m;
  }
  return m;
}

main(){
  int a,b,c; cin >> a >> b >> c;
  if(c % gcd(a,b) == 0) cout << "YES";
  else cout << "NO";
  cout << endl;
}
