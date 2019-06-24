#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int n;
vvi g;
vi used;
vvi d;

void bfs(int a){
  queue<int> q;
  rep(i,n) used[i] = 0;
  
  q.push(a);
  used[a] = 1;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    rep(i,g[x].size()){
      if(used[g[x][i]] == 0){
	used[g[x][i]] = 1;
	if(a == 0){
	  d[0][g[x][i]] = d[0][x] + 1;
	}else{
	  d[1][g[x][i]] = d[1][x] + 1;
	}
	q.push(g[x][i]);
      }
    }
  }
}
  

int main(){
  cin >> n;
  used.resize(n);
  g.resize(n);
  d.resize(2,vi(n));
  rep(i,n-1){
    int a,b; cin >> a >> b; a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  d[0][0] = 0; d[1][n-1] = 0;

  bfs(0);
  bfs(n-1);
  dump(d);
  int f = 0, s = 0;
  rep(i,n){
    if(d[0][i] <= d[1][i]) f++;
    else s++;
  }
  dump(f,s)
  if(f > s) cout << "Fennec\n";
  else cout << "Snuke\n";
}
