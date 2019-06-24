#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
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

int main(){
  int n; cin >> n;
  vi a(3*n); rep(i,3*n) cin >> a[i];

  priority_queue<int,vi,greater<int>> front;
  priority_queue<int> behind;
  vector<ll> red(n+1),blue(n+1);
  rep(i,n){
    red[0] += a[i];
    front.push(a[i]);
  }
  rep(i,n){
    blue[n] += a[2*n+i];
    behind.push(a[2*n+i]);
  }
  //cout << SUM(red) << endl << SUM(blue) << endl;

  rep(i,n){
    front.push(a[n+i]);
    red[i+1] = red[i] + a[n+i] - front.top();
    front.pop();
  }
  rep(i,n){
    behind.push(a[2*n-i-1]);
    blue[n-i-1] = blue[n-i] + a[2*n-i-1] - behind.top();
    behind.pop();
  }

  ll ans = red[0] - blue[0];
  rep(i,n) ans = max(ans, red[i+1] - blue[i+1]);

  //cout << SUM(red) << endl << SUM(blue) << endl;
  //rep(i,red.size()) cout << red[i] << " " << blue[i] << endl;
  cout << ans << endl;
}
