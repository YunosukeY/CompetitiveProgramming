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

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


main(){
  int n,k; cin >> n >> k;
  ll ans = 0;

  FOR(i,1,n+1){ // b
    if(i <= k) continue;
    //cout << i;
    ans += ll(n / i) * (i - k);
    //cout << ans;
    if(k != 0)
      ans += max((n%i) - k + 1,0);
    else ans += max((n%i)-k,0);
    //cout << ans << endl;
  }

  cout << ans << endl;
}
