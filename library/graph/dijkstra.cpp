#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;

using Cost = ll;
Cost inf = 1ll<<61;
class node {
public:
  ll v;
  Cost d;
  node(ll _a, Cost _b):v(_a),d(_b){}
  bool operator<(const node &n) const { return d > n.d; }
};
class edge {
public:
  ll to;
  Cost d;
  edge(){}
  edge(ll _to, Cost _d):to(_to),d(_d){}
};
class dijkstra{
public:
  vector<vector<edge>> G;
  vector<Cost> dist;
  vector<ll> prev;

  dijkstra(ll s,const vector<vector<edge>> &_G):G(_G){ // sからの最短経路
    dist.resize(G.size(),inf);
    //prev.resize(G.size(),-1);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      ll v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  //prev[G[v][i].to] = v;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }

  dijkstra(ll s,ll t,const vector<vector<edge>> &_G):G(_G){ // sからtへの最短経路
    dist.resize(G.size(),inf);
    //prev.resize(G.size(),-1);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      ll v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      if(v == t) break;
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  //prev[G[v][i].to] = v;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }

  vector<ll> getpath(ll t){ // tへの最短経路を返す
    vector<ll> path;
    while(t != -1){
      path.push_back(t);
      t = prev[t];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main(){
#define int ll
  int k; cin >> k;
  vector<vector<edge>> g(k,vector<edge>(2));
  rep(i,k){
    g[i][0] = edge((i+1)%k,1);
    g[i][1] = edge((i*10)%k,0);
  }
  dijkstra d(1,0,g);
  cout << d.dist[0]+1 << endl;
}
