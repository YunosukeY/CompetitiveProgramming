#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

struct UnionFind{
  vi data;

  UnionFind(int size){
    data.resize(size,-1);
  }

  bool unite(int x,int y){ // 併合
    x = root(x);
    y = root(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }

  bool same(int x, int y){ // 集合が同じか
    return root(x) == root(y);
  }

  int root(int x){ // どの集合か(代表元)
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int size(int x){ // 集合のサイズ
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

main(){
  int n,k,l; cin >> n >> k >> l;
  
  struct UnionFind a(n), b(n);

  rep(i,k){
    int p,q; cin >> p >> q;
    a.unite(p-1,q-1);
  }

  rep(i,l){
    int r,s; cin >> r >> s;
    b.unite(r-1,s-1);
  }
  
  a.print();
  b.print();

  map<pii,int> mp;
  rep(i,n){
    mp[pii(a.root(i),b.root(i))]++;
  }

  rep(i,n){
    cout << mp[pii(a.root(i),b.root(i))];
    if(i == n-1) cout << endl;
    else cout << " ";
  }
}
