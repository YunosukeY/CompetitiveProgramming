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
  ll n; cin >> n;

  ll a = 1, b = 1;
  ll x, y;
  ll m;
  rep(i,n){
    cin >> x >> y;
    m = max((a + x -1) / x, (b + y - 1) / y);
    m = max(m, ll(1));
    //cout << m << endl;
    a = m * x; b = m * y;
  }
  cout << a + b << endl;
}
