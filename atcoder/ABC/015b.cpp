#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

main(){
  int n;
  cin >> n;
  int c=0,a,sum=0;
  rep(i,n){
    cin >> a;
    if(a){
      c++;
      sum+=a;
    }
  }
  //cout << c << " " << sum << endl;
  cout << (sum+c-1)/c << endl;
}
