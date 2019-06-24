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
  int n,m; cin >> n >> m;
  vi a(m+2);
  int sum = 0;
  rep(i,n){
    int l,r,s; cin >> l >> r >> s;
    a[l] += s;
    a[r+1] -= s;
    sum += s;
  }
  rep(i,m+1) a[i+1] += a[i];
  //cout << sum << endl;
  cout << sum - *min_element(a.begin()+1,a.end()-1) << endl;
}
