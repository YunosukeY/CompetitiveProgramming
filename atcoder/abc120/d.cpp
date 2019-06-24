#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using vi  = vector<int>;
using pii = pair<int,int>;

class UnionFind{
public:
  vi data;

  UnionFind(int size){
    data.resize(size,-1);
    //rep(i, size) data[i] = -1;
  }

  bool unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }

  bool find(int x, int y){
    return root(x) == root(y);
  }

  int root(int x){ // どの集合か
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int size(int x){
    return -data[root(x)];
  }
};

signed main(){
  int n, m; cin >> n >> m;
  vector<pii> q(m);
  rep(i,m){
    cin >> q[i].first >> q[i].second;
    q[i].first--;
    q[i].second--;
  }
  reverse(all(q));

  vi ans = {n*(n-1)/2};
  int c = 0;
  UnionFind uf(n);
  rep(i,m){
    if(not uf.find(q[i].first,q[i].second)){
      int tmpa = uf.size(q[i].first);
      int tmpb = uf.size(q[i].second);
      uf.unite(q[i].first,q[i].second);
      //c += tmpc*(tmpc-1)/2 - tmpa*(tmpa-1)/2 - tmpb*(tmpb-1)/2;
      c += tmpa * tmpb;
    }
    ans.push_back(ans[0] - c);
  }
  reverse(all(ans));
  FOR(i,1,m+1) cout << ans[i] << endl;
}
