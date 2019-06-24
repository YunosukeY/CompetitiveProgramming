#include<bits/stdc++.h>
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

#define inf 1<<30

struct edge { int to,cap,rev; };

vector<edge> g[103];
bool used[103];

void add_edge(int from,int to,int cap){
  g[from].pb((edge){to,cap,g[to].size()});
  g[to].pb((edge){from,0,g[from].size()-1});
}

int dfs(int v,int t,int f){
  if(v == t) return f;
  used[v] = true;
  rep(i,g[v].size()){
    edge &e = g[v][i];
    if(!used[e.to] && e.cap>0){
      int d = dfs(e.to,t,min(f,e.cap));
      if(d > 0){
	e.cap -= d;
	g[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    memset(used,0,sizeof(used));
    int f = dfs(s,t,inf);
    if(f == 0) return flow;
    flow += f;
  }
}

int main(){
  int n; cin >> n;
  vi a(n),b(n),c(n),d(n);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,n) cin >> c[i] >> d[i];

  rep(i,n) add_edge(2*n,i,1);
  rep(i,n) add_edge(n+i,2*n+1,1);

  rep(i,n) rep(j,n){
    if(a[i] < c[j] and b[i] < d[j]) add_edge(i,n+j,1);
  }

  cout << max_flow(2*n,2*n+1) << endl;
}
