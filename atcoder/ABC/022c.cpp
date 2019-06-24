#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;
#define inf 999999999 

main(){
  int n,m; cin >> n >> m;
  vii d(n-1);//距離
  vi ad,addis;//1に隣接するか家
  rep(i,n-1){
    d[i].resize(n-1);
    rep(j,n-1) d[i][j] = inf;
  }
  rep(i,m){
    int u,v,l; cin >> u >> v >> l;
    u-=2; v-=2;
    if(u != -1 and v != -1){
      d[u][v] = l; d[v][u] = l;
    }
    if(u == -1){
      ad.push_back(v);
      addis.push_back(l);
    }
    if(v == -1){
      ad.push_back(u);
      addis.push_back(l);
    }
  }
  
  rep(k,n-1) rep(i,n-1) rep(j,n-1) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
  /*
  rep(i,ad.size()) cout << ad[i];
  cout << endl;
  rep(i,n-1){
    rep(j,n-1) cout << d[i][j] << "\t";
    cout << endl;
  }
  */
  int minv = inf;
  rep(i,ad.size()) FOR(j,i+1,ad.size()){
    //cout << i << "\t" << j << "\t" << addis[i] << "\t" << d[ad[i]][ad[j]] << "\t" << addis[j] << endl;
    minv = min(minv,addis[i]+d[ad[i]][ad[j]]+addis[j]);
  }
  if(minv == inf) cout << -1 << endl;
  else cout << minv << endl;
}
