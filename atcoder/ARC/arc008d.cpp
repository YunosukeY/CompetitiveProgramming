#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#define showvv(v)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

#define MAX 100000

struct segtree {
  int N;
  function<double(double)> dat[2*MAX];
  segtree() {}
  segtree(int n) {
    N = 1;
    while(N < n) N *= 2;
    for(int i = 0; i < 2*N-1; i++)
      dat[i] = [](double x){ return x; };
  }
  // update k th element
  void update(int k, double a, double b) {
    k += N-1; // leaf
    dat[k] = [=](double x){ return a*x+b; };
    while(k > 0) {
      k = (k - 1) / 2;
      function<double(double)> left = dat[k*2+1], right = dat[k*2+2];
      dat[k] = [=](double x){ return right(left(x)); };
    }
  }

  // updateだけできれば良い
};

int main(){
  // input
  ll n, m; cin >> n >> m;
  
  map<ll, ll> mp; // 座標圧縮用
  vector<ll> p(m);
  vector<double> a(m), b(m);
  rep(i, m){
    cin >> p[i] >> a[i] >> b[i];
    p[i]--;
    mp[p[i]];
  }

  int i = 0;
  for(auto&& x : mp){ // 座標圧縮
    x.second = i;
    i++;
  }

  struct segtree seg(i);
  double minv = 1, maxv = 1;

  rep(i, m){
    seg.update(mp[p[i]], a[i], b[i]);
    double tmp = seg.dat[0](1.0);
    minv = min(minv, tmp);
    maxv = max(maxv, tmp);
  }

  printf("%.10f\n%.10f\n", minv, maxv);
}
