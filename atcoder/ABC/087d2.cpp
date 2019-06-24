#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

#define inf 1<<29

int check[100000];
vector<pii> g[100000];
int n;
int indeg[100000];
int posi[100000];
int indeg2[100000];

bool bfs(int i){
  queue<int> q;
  q.push(i);
  check[i]=1;
  while(!q.empty()){
    int a = q.front();
    q.pop();
    int s = g[a].size();
    rep(j,s){
      indeg[g[a][j].first]--;
      if(posi[g[a][j].first]!=0 and posi[a]+g[a][j].second!=posi[g[a][j].first])
	return false;
      posi[g[a][j].first]=posi[a]+g[a][j].second;
      if(indeg[g[a][j].first]==0 and check[g[a][j].first]==0){
	check[g[a][j].first]=1;
	q.push(g[a][j].first);
      }
    }
  }
  return true;
}
 
main(){
  int m; cin >> n >> m;
  int l,r,d;
  
  rep(i,m){
    cin >> l >> r >> d;
    g[--l].pb(make_pair(--r,d));
    indeg[r]++;
    indeg2[r]++;
  }
 
  rep(i,n){
    if(indeg[i]==0 and check[i]==0)
      if(bfs(i)==false){
	cout << "No\n";
	return 0;
      }
  }

  int maxv = 0;
 
  rep(i,n){
    if(indeg2[i]!=0 and posi[i]==0){
      cout << "No\n";
      return 0;
    }
    maxv = max(maxv,posi[i]);
  }
 
  if(maxv > pow(10,9)){
    cout << "No\n";
    return 0;
  }
  
  cout << "Yes\n";
  //rep(i,n) cout << posi[i];
}
