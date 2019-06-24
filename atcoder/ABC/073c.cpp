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

main(){
  int n,t; cin >> n >> t;
  int a0,a1; cin >> a0;
  int sum = 0;
  rep(i,n-1){
    cin >> a1;
    if(a1-a0 >=t) sum += t;
    else sum += (a1 - a0);
    a0 = a1;
  }
  sum += t;
  cout << sum << endl;
}
