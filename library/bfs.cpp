#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
typedef long long ll;

#define int ll

vector<vector<int>> g,child;
vector<int> par,d;

int s(int p){ // pを根とする部分木のサイズを返す
  int res = 0;
  rep(i, child[p].size()){
    res += s(child[p][i]);
  }
  return res + 1;
}

void bfs(int s){ // sを根としてbfs
  queue<int> q;
  d[s] = 0;
  q.push(s);
  
  while(!q.empty()){
    int next = q.front();
    q.pop();
    
    rep(i, g[next].size()){
      int c = g[next][i];
      
      if(d[c] == -1){
	// par[c] = next;
	// child[next].push_back(c);
	d[c] = d[next] + 1;
	q.push(c);
      }
    }
  }
}

vector<int> getpath(int t){
  vector<int> path;
  
  while(t != -1){
    path.push_back(t);
    t = par[t];
  }
  
  reverse(path.begin(), path.end());

  return path;
}

main(){
  int n,x,y;
  cin >> n >> x >> y;
  x--;
  y--;

  g.resize(n);
  child.resize(n);
  par.resize(n, -1);
  d.resize(n, -1);

  rep(i, n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bfs(x);

  int a,b = y;

  while(1){
    a = par[b];
    if(a == x) break;
    b = a;
  }
  int ca = 1, cb = 0;
  //rep(i,n) cout << s(i) << endl;
  cb = s(y);
  rep(i,child[x].size()){
    if(child[x][i] != b) ca += s(child[x][i]);
  }
  //cout << c << d << endl;
  cout << n * (n-1) - ca * cb << endl;
}
