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

vector<ll> lucas(87);

main(){
  int n; cin >> n;
  lucas[0]=2; lucas[1]=1;
  if(n==1) cout << 2;
  else{
    FOR(i,2,n+1) lucas[i]=lucas[i-1]+lucas[i-2];
    cout << lucas[n];
  }
  cout << endl;
}
