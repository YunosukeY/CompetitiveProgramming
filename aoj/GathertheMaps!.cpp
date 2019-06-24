#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define int ll

struct UnionFind{
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

  int root(int x){
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

main()
{
  while(1){
    int n; cin >> n;
    if(n == 0) break;

    vvi day(30);
    rep(i,n){
      int m; cin >> m;
      rep(j,m){
	int d; cin >> d; d--;
	day[d].pb(i);
      }
    }
    struct UnionFind uf(n);
    bool notgather = true;
    rep(i,30){
      rep(j,sz(day[i])-1){
	uf.unite(day[i][0],day[i][j+1]);
      }
      bool ans = true;
      rep(j,n-1){
	if(not uf.find(0,j+1)){
	  ans = false;
	  break;
	}
      }
      if(ans){
	cout << i+1 << endl;
	notgather = false;
	break;
      }
    }
    if(notgather) cout << -1 << endl;
  }
}
