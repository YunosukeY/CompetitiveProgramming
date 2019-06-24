#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>T add(const T &a, const T &b){return (a+b)%mod;}

// rank無しなのでlog n
class UnionFind{
public:
  vi data;
  int s; // 成分数

  UnionFind(int size){
    data.resize(size,-1);
    s = size;
  }

  bool unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      data[y] = x;
      s--;
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

  void print(){
    cout << "i :\t";
    rep(i, data.size()) cout << i << "\t";
    cout << endl;
    cout << "data :\t";
    rep(i, data.size()) cout << root(i) << "\t";
    cout << endl;
  }
};

signed main(){
  int n; cin >> n;
  vi x(n), y(n); rep(i,n) cin >> x[i] >> y[i];
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  int ans = inf;
  rep(i,n) rep(j,n){ // i, jの差をp, qとする
    if(i == j) continue;
    int p = x[i]-x[j], q = y[i]-y[j];
    UnionFind uf(n);
    rep(a,n) rep(b,n){
      if(x[a]-x[b]==p and y[a]-y[b]==q) uf.unite(a,b);
    }
    dump(uf.s);
    ans = min(ans, uf.s);
  }
  cout << ans << endl;
}
