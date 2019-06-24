#include <bits/stdc++.h>
using namespace std;
#include "../dump.hpp"

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;

vvi g;
vi d;

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
	d[c] = d[next] + 1;
	q.push(c);
      }
    }
  }
}

signed main(){
  int n, m, k; cin >> n >> m >> k;
  vector<int> dar(m);
  rep(i,m){
    cin >> dar[i];
    dar[i]--;
  }
  //dump(dar);
  vvi v(n,vi(k));
  rep(i,n) rep(j,k){
    cin >> v[i][j];
    v[i][j]--;
  }
  //dump(v);
  g.resize(1<<m);
  d.resize(1<<m,-1);
  rep(i,1<<m){
    rep(j,k){
      //dump(i);
      // 集合iからj番目の遷移を使った時に集合がどうなるか
      int next = 0;
      rep(x,m){ // x番目の部屋
	if((i>>x)&1){ // x番目の部屋に人がいて
	  //dump(x,v[dar[x]][j]);
	  auto itr = find(all(dar),v[dar[x]][j]); // 部屋xからj番目の遷移先が
	  if(itr != dar.end()){ // 暗い部屋なら
	    //dump(itr-dar.begin());
	    next |= 1<<(itr-dar.begin()); // 遷移先に増やす
	  }
	}
      }
      //dump(next);
      g[i].push_back(next);
    }
  }
  //dump(g);
  bfs((1<<m)-1);
  //dump(d);
  cout << d[0] << endl;
}
