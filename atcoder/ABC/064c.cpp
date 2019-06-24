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
  int n; cin >> n;
  int a;
  vi c(8);
  int over=0,count=0;
  rep(i,n){
    cin >> a;
    a /= 400;
    if(a < 8) c[a]++;
    else over++;
  }
  rep(i,8) if(c[i]) count++;
  if(count || !over) cout << count;
  else cout << 1;
  cout << " " << count + over << endl;
}
