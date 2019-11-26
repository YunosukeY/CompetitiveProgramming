#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using vi  = vector<int>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

int n; // ノード数
vector<vector<pii>> g;
vi d;

pii bfs(int s){ // sを根としてbfs
  d.clear();
  d.resize(n,-1);
  queue<int> q;
  d[s] = 0;
  int maxd = 0;
  int pos = s;
  q.push(s);
  
  while(!q.empty()){
    int next = q.front();
    q.pop();
    
    rep(i, g[next].size()){
      int c = g[next][i].first;
      
      if(d[c] == -1){
	d[c] = d[next] + g[next][i].second;;
	if(chmax(maxd,d[c])) pos = c;
	q.push(c);
      }
    }
  }
  // sから最も遠いノードとその距離を返す
  return pii(pos,maxd);
}

int diameter(){
  int s = -1;
  rep(i,n) if(g[i].size() != 0) s = i;
  if(s == -1) return 0;
  pii a = bfs(s);
  return bfs(a.first).second;
}

signed main(){
  while(cin >> n, n){
    g.clear();
    g.resize(n);
    vi p(n-1), dis(n-1);
    rep(i,n-1){
      cin >> p[i];
      p[i]--;
    }
    rep(i,n-1) cin >> dis[i];
    rep(i,n-1){
      g[i+1].emplace_back(p[i],dis[i]);
      g[p[i]].emplace_back(i+1,dis[i]);
    }
    vi leaf;
    rep(i,n)
      if(g[i].size() == 1) leaf.push_back(i);
    rep(k,leaf.size()){
      int to = g[leaf[k]][0].first;
      g[leaf[k]].clear();
      rep(i,g[to].size())
	if(g[to][i].first == leaf[k]){
	  g[to].erase(g[to].begin()+i);
	  break;
	}
    }
    int sumv = 0;
    rep(i,n) rep(j,g[i].size()) sumv += g[i][j].second; // 既に2倍されている
    cout << accumulate(all(dis),0) + sumv - diameter() << endl;
  }
}
