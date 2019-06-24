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
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  int min_a = *min_element(all(a)), max_a = *max_element(all(a));
  int min_cost = 1 << 29, cost;

  FOR(i,min_a,max_a + 1){
    cost = 0;
    rep(j,n) cost += (a[j] - i) * (a[j] - i);
    min_cost = min(min_cost, cost);
  }
  cout << min_cost << endl;
}
