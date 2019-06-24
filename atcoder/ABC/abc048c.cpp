#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  ll n, x; cin >> n >> x;
  vector<ll> a(n); rep(i,n) cin >> a[i];

  ll ans = 0;
  if(x < a[0]){
    ans += a[0] - x;
    a[0] = x;
  }
  rep(i,n-1){
    if(a[i] + a[i + 1] > x){
      ans += a[i] + a[i + 1] - x;
      a[i + 1] = x - a[i];
    }
  }
  cout << ans << endl;
}
