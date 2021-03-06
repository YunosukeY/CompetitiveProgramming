#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#define showvv(v)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
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
  vector<ll> a(n); rep(i,n) cin >> a[i];
  a.pb(0); n++;
  ll ans = 0;
  ll tmp = 0;
  rep(i,n){
    ans += abs(a[i] - tmp);
    tmp = a[i];
  }

  tmp = 0;
  rep(i,n-1){ // i個目を飛ばした時
    ll x = ans;
    ans -= abs(a[i+1]-a[i]) + abs(a[i]-tmp);
    ans += abs(a[i+1]-tmp);
    cout << ans << endl;
    ans = x;
    tmp = a[i];
  }
}
