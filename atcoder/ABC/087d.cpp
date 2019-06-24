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
int posi[100000];

bool bfs(int i){
  queue<int> q;
  q.push(i);
  check[i]=1;
  while(!q.empty()){
    int a = q.front();
    q.pop();
    int s = g[a].size();
    rep(j,s){
      if(check[g[a][j].first]==0){
	posi[g[a][j].first]=posi[a]+g[a][j].second;
	check[g[a][j].first]=1;
	q.push(g[a][j].first);
      }else{
	if(posi[g[a][j].first]!=posi[a]+g[a][j].second){
	  return false;
	}else continue;
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
    g[r].pb(make_pair(l,-1*d));
  }

  rep(i,n){
    if(check[i]==0)
      if(bfs(i)==false){
	cout << "No\n";
	return 0;
      }
  }

  cout << "Yes\n";
}
