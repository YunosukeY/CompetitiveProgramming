#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

int n; // ノード数
vvi g;

pii bfs(int s){ // sを根としてbfs
  vi d(n,-1);
  queue<int> q;
  d[s] = 0;
  int maxd = 0;
  int pos = s;
  q.push(s);
  
  while(!q.empty()){
    int next = q.front();
    q.pop();
    
    rep(i, g[next].size()){
      int c = g[next][i];
      
      if(d[c] == -1){
	d[c] = d[next] + 1;
	if(chmax(maxd,d[c])) pos = c;
	q.push(c);
      }
    }
  }
  // sから最も遠いノードとその距離を返す
  return pii(pos,maxd);
}

// template<typename I, typename D>
int diameter(){
  pii a = bfs(0);
  return bfs(a.first).second;
}

signed main(){
  cin >> n;
  g.resize(n);
  rep(i,n-1){
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b); g[b].push_back(a);
  }
  int b = diameter();
  if(b % 3 == 1) cout << "Second" << endl;
  else cout << "First" << endl;
}
