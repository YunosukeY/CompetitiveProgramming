#include<bits/stdc++.h>

#ifdef LOCAL
#include "../../dump.hpp"
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

#define MAX 100000

int main(){
  int n,C; cin >> n >> C;
  vvi a(2*MAX+2, vi(C));
  int s,t,c;
  rep(i,n){
    cin >> s >> t >> c;
    a[2*s-1][c-1]++;
    a[2*t+1][c-1]--;
  }
  ll ans = 0;
  rep(i,2*MAX+1){
    ll tmp = 0;
    rep(j,C){
      a[i+1][j] += a[i][j];
      if(a[i][j]) tmp++;
    }
    ans = max(ans,tmp);
  }
  
  cout << ans << endl;
}
