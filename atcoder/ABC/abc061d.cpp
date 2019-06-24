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
  int n,m; cin >> n >> m;
  vector<ll> d(n,1ll<<59); d[0] = 0;
  vector<pair<pair<ll,ll>,ll>> edge;
  ll a,b,c;
  rep(i,m){
    cin >> a >> b >> c; a--; b--; c *= -1;
    edge.pb(make_pair(pii(a,b),c));
    if(a == 0) d[b] = c;
  }

  // ベルマンフォード
  rep(i,n-1) rep(j,m){
    ll u = edge[j].fst.fst, v = edge[j].fst.snd, c = edge[j].snd;
    if(d[v] > d[u] + c)
      d[v] = d[u] + c;
  }
  dump(d);
  ll ans = d[n-1];

  // 負経路検出
  vi negative(n);
  rep(i,n) rep(j,m){
    ll u = edge[j].fst.fst, v = edge[j].fst.snd, c = edge[j].snd;
    if(d[v] > d[u] + c){
      d[v] = d[u] + c;
      negative[v] = 1;
    }
    if(negative[u]) negative[v] = 1;
  }

  dump(d,negative);
  if(negative[n-1]) cout << "inf\n";
  else cout << -ans << endl;  
}
