#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n; cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }
  //cout << sum << endl;

  ll minv = 1000000000000000000LL;
  ll tmp = 0;
  rep(i, n - 1){
    tmp += a[i];
    minv = min(minv, abs(sum - 2 * tmp));
    //cout << minv << endl;
  }
  cout << minv << endl;
}
