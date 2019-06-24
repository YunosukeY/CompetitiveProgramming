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
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
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
template<class T>void add(T &a, const T &b){a += b; a %= mod;}

// rank無しなのでlog n
class UnionFind{
public:
  vi data;
  vi e;

  UnionFind(int size){
    data.resize(size,-1);
    e.resize(size);
  }

  bool unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      data[y] = x;
      e[x] += e[y];
    }
    e[x]++;
    return x != y;
  }

  bool find(int x, int y){
    return root(x) == root(y);
  }

  int root(int x){ // どの集合か
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int nodesize(int x){
    return -data[root(x)];
  }

  int edgesize(int x){
    return e[root(x)];
  }
};

signed main(){
  int n; cin >> n;
  vi a(n), b(n); rep(i,n) cin >> a[i] >> b[i];
  map<int,int> m;
  rep(i,n){
    m[a[i]];
    m[b[i]];
  }
  {
    int i = 0;
    for(auto &x : m){
      x.second = i;
      i++;
    }
  }
  int s = m.size();
  UnionFind uf(s);
  rep(i,n){
    uf.unite(m[a[i]],m[b[i]]);
  }
  set<int> rs;
  int ans = 0;
  for(auto x : m){
    int r = uf.root(x.second);
    if(rs.count(r) == 0){
      rs.insert(r);
      ans += min(uf.nodesize(r),uf.edgesize(r));
    }
  }
  cout << ans << endl;
}
