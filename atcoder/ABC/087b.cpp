#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int a,b,c,x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  rep(i,a+1) rep(j,b+1) rep(k,c+1){
    if(500*i+100*j+50*k == x) ans++;
  }
  cout << ans << endl;
			     
}
