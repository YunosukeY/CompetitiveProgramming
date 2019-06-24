#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using ll = long long;
using vi  = vector<int>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

/* 0-indexed, [0, n)
 *
 * requirements: let a, b, c in T
 *   op(op(a, b), c) = op(a, op(b, c))
 *   op(a, e) = op(e, a) = e
 */
template<typename T, typename E> class SegmentTree {
public:
  typedef function<T (T, T)> Operator;
  typedef function<T (T, E)> Apply;

  vector<T> data;
  ll n;        // size of elements (2^x alignment)
  T e;         // identity of monoid
  Operator op; // binary operator of monoid
  Apply apply; // apply effect to monoid

  // construct with size of elements
  SegmentTree(ll _n, T _e, Operator _op, Apply _apply): e(_e), op(_op), apply(_apply) {
    for(n = 1; n < _n; n *= 2);
    data.resize(n * 2 - 1, e);
  }

  // construct with initial values
  SegmentTree(const vector<T> &vec, T _e, Operator _op, Apply _apply): e(_e), op(_op), apply(_apply) {
    for(n = 1; n < vec.size(); n *= 2);
    data.resize(n * 2 - 1, e);
    FOR(i, 0, vec.size()) data[i + n - 1] = vec[i];
    for(ll i = n - 2; i >= 0; i--) data[i] = op(data[i * 2 + 1], data[i * 2 + 2]);
  }

  // query for [a, b)
  T query(ll a, ll b) { return query(a, b, 0, 0, n); }
  T query(ll a, ll b, ll k, ll l, ll r) {
    if(r <= a || b <= l) return e;
    if(a <= l && r <= b) return data[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return op(vl, vr);
  }

  // update value at k
  void update(ll k, E x) {
    k += n - 1;
    data[k] = apply(data[k], x);
    while(k > 0) {
      k = (k - 1) / 2;
      data[k] = op(data[k * 2 + 1], data[k * 2 + 2]);
    }
  }
};

ll ext_gcd(ll a, ll b, ll &x, ll &y){ // ax+by=gcd(a,b)なるx,y,gcdを返す
  if(b == 0){
    x = 1; y = 0; return a;
  }
  ll q = a / b;
  ll g = ext_gcd(b, a-q*b, x, y);
  ll z = x - q * y;
  x = y; y = z;
  return g;
}

signed main(){
  SegmentTree<int, int>::Operator op = [](int a, int b){
    int x, y;
    return ext_gcd(a,b,x,y);
  };
  SegmentTree<int, int>::Apply apply = [](int a, int x){
    return x;
  };

  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];

  SegmentTree<int, int> segtree(a, 0, op, apply);

  int ans = 0;
  rep(i,n){
    int x,y;
    chmax(ans, ext_gcd(segtree.query(0,i),segtree.query(i+1,a.size()),x,y));
  }
  cout << ans << endl;
}
