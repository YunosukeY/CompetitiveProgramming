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
  ll x; cin >> x;
  ll ans = (x / 11) * 2;
  x %= 11;
  //cout << ans << " " << x << endl;
  if(0 < x and x <= 6){
    ans++;
    x -= 6;
  }else if(6 < x){
    ans += 2;
    x -= 11;
  }
  cout << ans << endl;
}
