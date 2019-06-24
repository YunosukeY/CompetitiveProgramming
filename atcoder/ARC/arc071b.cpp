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

const ll mod = 1e9 + 7;

int main(){
  int n,m; cin >> n >> m;
  ll sumx = 0, sumy = 0;

  rep(i,n){
    ll x; cin >> x;
    (sumx += ll(2 * i - n + 1) * x) %= mod;
  }
  rep(i,m){
    ll y; cin >> y;
    (sumy += ll(2 * i - m + 1) * y) %= mod;
  }
  cout << (sumx * sumy) % mod << endl;
}
