#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond(b);i<i##_cond;++i)
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) ((int)(x).size())

typedef vector<int> vi;
typedef vector<vi> vvi;

#define inf 1<<30

vector<int> prime(int n){
  // n以下の素数を要素に持つviを返す
  // 時間 O(n ln ln n)
  // 答えのサイズ n / ln n

  vector<bool> isprime(n+1, true);
  vector<int> ans;
  isprime[0] = isprime[1] = false;
  FOR(i, 2, n+1)
    if(isprime[i]){
      ans.push_back(i);
      for(int j = 2 * i; j <= n; j += i) isprime[j] = false;
    }
  return ans;
}

// dinic
struct max_flow {
    struct edge { int to, cap, rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int _V) : V(_V) { G.assign(_V,vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int run(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, inf)) > 0) ret += f;
        }
        return ret;
    }
};

int main(){  
  vi p = prime(10000000);
  
  while(1){
    // input
    int m, n; cin >> m >> n; if(m == 0) break;
    vi b(m); rep(i, m) cin >> b[i]; sort(rall(b));
    vi r(n); rep(i, n) cin >> r[i]; sort(rall(r));

    // フロー初期化
    struct max_flow f(n+m+2); // 左右+1+1
    rep(i,m) f.add_edge(0, i+1, 1); // sから左側
    rep(i,n) f.add_edge(m+i+1, m+n+1, 1); // 右側からt

    // 同じ素因数を持つとき辺を追加
    rep(i,m) rep(j,n) rep(k,sz(p)){
      if(b[i] < p[k] or r[j] < p[k]) break;
      if(b[i] % p[k] == 0 and r[j] % p[k] == 0){
	f.add_edge(i+1, m+j+1, 1);
	break;
      }
    }

    // フローを流す
    int ans = f.run(0,n+m+1);
    cout << ans << endl;
  }
}
