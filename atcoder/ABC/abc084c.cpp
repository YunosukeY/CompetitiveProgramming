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

#define mod 1000000007

main(){
  int n; cin >> n;
  vi a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(all(a));
  //rep(i, n) cout << a[i] << " "; cout << endl;
  sort(all(b));
  //rep(i, n) cout << b[i] << " "; cout << endl;
  sort(all(c));
  //rep(i, n) cout << c[i] << " "; cout << endl;

  ll ans = 0, tmp;
  rep(i, n){ // 上段をa[i]にした場合
    auto itr = lower_bound(all(b), a[i] + 1, less<int>());
    int s = itr - b.begin();
    FOR(j, s, n){
      //cout << "i : " << i << ", j : " << j << endl;
      auto it = lower_bound(all(c), b[j] + 1, less<int>());
      ans += c.end() - it;
      //cout << ans << endl;
    }
  }
  cout << ans << endl;
}
