#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
typedef long long ll;

int n;
vector<vector<pair<int,int>>> g; // fst : node, snd, cost
vector<vector<int>> child;
vector<int> par,d;

int s(int p){ // pを根とする部分木のサイズを返す
  int res = 0;
  rep(i,child[p].size()){
    res += s(child[p][i]);
  }
  return res + 1;
}

void bfs(int s){ // sを根として01bfs
  deque<int> q;
  d[s] = 0;
  q.push_back(s);
  
  while(!q.empty()){
    int next = q.front();
    q.pop_front();
    
    rep(i,g[next].size()){
      pair<int,int> c = g[next][i];
      
      if(d[c.fst] > d[next] + c.snd){
	par[c.fst] = next;
	//child[next].push_back(c.fst); //古いものがあるかもしれない
	d[c.fst] = d[next] + c.snd;
	if(c.snd == 0) q.push_front(c.fst);
	else if(c.snd == 1) q.push_back(c.fst);
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

void setchild(){ // bfsの後
  rep(i,n)
    child[par[i]].push_back(i);
}

main()
{
  int x,y; cin >> n >> x >> y; x--; y--;
  g.resize(n);
  child.resize(n);
  par.resize(n,-1);
  d.resize(n,inf);
  rep(i,n-1){
    int a,b,c; cin >> a >> b >> c; a--; b--;
    g[a].push_back(pair<int,int>(b,c)); g[b].push_back(pair<int,int>(a,c));
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
