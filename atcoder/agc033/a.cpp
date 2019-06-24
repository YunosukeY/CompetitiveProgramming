#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>void add(T &a, const T &b){a += b; a %= mod;}

vi dx = {0,1,0,-1};
vi dy = {1,0,-1,0};

signed main(){
  int h, w; cin >> h >> w;
  vs a(h);
  vvi check(h,vi(w));
  vvi dist(h,vi(w,-1));
  queue<pii> q;
  rep(i,h){
    cin >> a[i];
    rep(j,w){
      if(a[i][j] == '#'){
	dist[i][j] = 0;
	check[i][j] = 1;
	q.push(pii(i,j));
      }
    }
  }
  while(not q.empty()){
    int x = q.front().first, y = q.front().second;
    q.pop();
    
    rep(k, 4){
      int nx = x + dx[k], ny = y + dy[k];
      if(0 <= nx and nx < h and 0 <= ny and ny < w){
	if(dist[nx][ny] == -1){
	  dist[nx][ny] = dist[x][y] + 1;
	  q.push(pii(nx,ny));
	}
      }
    }
  }

  int ans = -inf;
  rep(i,h){
    rep(j,w){
      ans = max(ans,dist[i][j]);
    }
  }
  cout << ans << endl;
}
