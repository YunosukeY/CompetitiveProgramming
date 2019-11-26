#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define pb push_back
#define eb emplace_back
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
  vi flow;
  vi area;

  UnionFind(int size){
    data.resize(size,-1);
    flow.resize(size);
    area.resize(size);
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

int main(){
  int d; cin >> d;
  rep(_,d){
    int n; cin >> n;
    vi b(n+2), h(n+2);
    b[0] = 0;
    b[n+1] = 100;
    h[0] = h[n+1] = 50;
    rep(i,n) cin >> b[i+1] >> h[i+1];
    UnionFind uf(n+1);
    rep(i,n+1)
      uf.area[i] = (b[i+1] - b[i]) * 30;
    dump(uf.area);
    
    int m; cin >> m;
    vi f(m), a(m); rep(i,m) cin >> f[i] >> a[i];
    auto calcSec = [&](int pos){
      return (upper_bound(all(b),pos) - b.begin()) - 1;
    };
    rep(i,m)
      uf.flow[calcSec(f[i])] += a[i];
    dump(uf.flow);

    int l; cin >> l;
    vi p(l), t(l); rep(i,l) cin >> p[i] >> t[i];
  }
}
