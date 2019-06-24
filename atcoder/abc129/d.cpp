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
#define mp make_pair
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

  UnionFind(int size){
    data.resize(size,-1);
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
  int h, w; cin >> h >> w;
  vs s(h); rep(i,h) cin >> s[i];
  UnionFind tate(h*w), yoko(h*w);
  rep(i,h) rep(j,w){
    if(s[i][j] == '#') continue;
    if(0 < i and s[i-1][j] == '.')
      tate.unite((i-1)*w+j,i*w+j);
    if(0 < j and s[i][j-1] == '.')
      yoko.unite(i*w+j-1,i*w+j);
  }
  int ans = 0;
  rep(i,h) rep(j,w){ // (i,j) においたとき
    int tmpa = i*w+j;
    dump(i,j);
    int tmpb = tate.size(tmpa) + yoko.size(tmpa) - 1;
    dump(tmpb);
    ans = max(ans, tmpb);
  }
  cout << ans << endl;
}
