#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;
constexpr int inf = 1<<30;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

using Cost = int;
class node {
public:
  int v;
  Cost d;
  node(int _a, Cost _b):v(_a),d(_b){}
  bool operator<(const node &n) const { return d > n.d; }
};
class edge {
public:
  int to;
  Cost d;
  edge(){}
  edge(int _to, Cost _d):to(_to),d(_d){}
};
class dijkstra{
public:
  vector<vector<edge>> G;
  vector<Cost> dist;

  dijkstra(int s,const vector<vector<edge>> &_G):G(_G){ // sからの最短経路
    dist.resize(G.size(),inf);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      int v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }
};

signed main(){
  int N, M, H, K;
  while(cin >> N >> M >> H >> K, N){
    // input
    vvi e(M,vi(5));
    rep(i,M){
      rep(j,5) cin >> e[i][j];
      e[i][0]--;
      e[i][1]--;
      e[i][4]--;
    }
    int S, T, P; cin >> S >> T >> P; S--; T--;
    vi d(P);
    vvi k(P);
    rep(i,P){
      int l;
      cin >> l >> d[i];
      k[i].resize(l);
      rep(j,l){
	cin >> k[i][j];
	k[i][j]--;
      }
    }

    // 1 day passで作れる集合を求める
    vvi dp(1<<K,vi(P+1,inf));
    rep(j,P+1) dp[0][j] = 0;
    vi bitk(P); // kのbit表現
    rep(i,P) rep(j,k[i].size()) bitk[i] += 1<<k[i][j];
    rep(i,1<<K) rep(j,P){
      chmin(dp[i][j+1],dp[i][j]); // j番目を使わない時
      int next = i | bitk[j];
      chmin(dp[next][j+1], dp[i][j] + d[j]); // j番目を使うとき
    }

    // 作れる集合ごとに最小コストを求める
    int ans = inf;
    rep(i,1<<K){
      if(dp[i][P] == inf) continue; // 作れない

      // 拡張グラフ構築
      vector<vector<edge>> g(N*(H+1));
      rep(j,M){
	int a = e[j][0], b = e[j][1], c = e[j][2], h = e[j][3], r = e[j][4];
	if((i>>r)&1) c = 0;
	rep(l,H-h+1){ // スタート時間
	  g[l*N+a].emplace_back((l+h)*N+b, c);
	  g[l*N+b].emplace_back((l+h)*N+a, c);	    
	}
      }

      dijkstra dijk(S, g);
      rep(j,H+1)
	chmin(ans, dijk.dist[j*N+T]+dp[i][P]);
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
  }
}
