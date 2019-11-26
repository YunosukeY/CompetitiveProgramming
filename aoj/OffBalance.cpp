#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i) // ROF(i,n,0)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで降順
#define uni(a) (a).erase(unique(all(a)),(a).end())
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

int h, w;

bool isin(int x, int y){
  return 0 <= x and x < h and 0 <= y and y < w;
}

class UnionFind{
public:
  vi data;
  vi wsum; // weighted sum

  UnionFind(){}

  void init(int size){
    data.clear();
    data.resize(size,-1);
    wsum.clear();
    wsum.resize(size);
  }
  
  bool unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      wsum[x] += wsum[y];
      data[y] = x;
    }
    return x != y;
  }

  bool find(int x, int y){
    return root(x) == root(y);
  }

  int root(int x){
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int size(int x){
    return -data[root(x)];
  }
};

// i,h,xが同じ方向、j,w,yが同じ方向

vi dx = {0,1}, dy = {1,0};

UnionFind uf();
map<int,int> mp;
vvi tree;

bool rec(int s){
  bool f = true;
  for(
}

signed main(){
  while(cin >> w >> h, w){
    // input
    vs p(h); ROF(i,h,0) cin >> p[i];

    // グループ化
    uf.init(h*w);
    mp.clear();
    int cnt = 0;
    rep(i,h) rep(j,w) uf.wsum[i*w+j] = j;
    rep(i,h) rep(j,w) rep(k,2){
      int nx = i + dx[k], ny = j + dy[k];
      if(not isin(nx,ny)) continue;
      if(p[i][j] != '.' and p[nx][ny] != '.' and p[i][j] == p[nx][ny]){
	uf.unite(i*w+j, nx*w+ny);
	if(mp.count(uf.root(i*w+j)) == 0) mp[uf.root(i*w+j)] = cnt++;
	if(mp.count(uf.root(nx*w+ny)) == 0) mp[uf.root(nx*w+ny)] = cnt++;
      }
    }
    dump(uf.data, mp);

    // 木を作る
    tree.clear();
    tree.resize(mp.size());
    rep(i,h-1) rep(j,w){
      if(p[i][j] != '.' and p[i+1][j] != '.' and p[i][j] != p[i+1][j]){
	tree[mp[uf.root(i*w+j)]].push_back(mp[uf.root((i+1)*w+j)]);
      }
    }
    rep(i,tree.size()){
      sort(all(tree[i]));
      uni(tree[i]);
    }
    dump(tree);

    // dfs
    bool f = true;
    set<int> s;
    {
      int i = 0;
      rep(j,w) if(p[i][j] != '.') f &= rec(mp[uf.root(i*w+j)]);
    }
    if(f) cout << "STABLE\n";
    else cout << "UNSTABLE\n";
  }
}
