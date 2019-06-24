#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using ll = long long;
using vi = vector<int>;

// rank無しなのでlog n
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
  int n; cin >> n;
  vector<int> x(n), y(n); rep(i,n) cin >> x[i] >> y[i];
  
  #define MAX 100005
  UnionFind ufx(MAX), ufy(MAX);
  vector<vector<int>> sx(MAX), sy(MAX);
  rep(i,n){
    sx[x[i]].push_back(y[i]);
    sy[y[i]].push_back(x[i]);
  }
  rep(i,MAX){
    FOR(j,1,sx[i].size())
      ufy.unite(sx[i][0], sx[i][j]);
    FOR(j,1,sy[i].size())
      ufx.unite(sy[i][0], sy[i][j]);
  }
  vector<int> usedx(MAX);
  int maxv = 0;
  rep(i,n)
    if(usedx[ufx.root(x[i])] == 0){
      maxv += ufx.size(x[i]) * ufy.size(y[i]);
      usedx[ufx.root(x[i])] = 1;
    }
  cout << maxv - n << endl;
}
