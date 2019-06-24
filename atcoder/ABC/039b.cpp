#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
typedef vector<int> vi;
typedef vector< vi > vii;

int main(){
  long long n;
  cin >> n;
  cout << sqrt(sqrt(n)) << endl;
}
