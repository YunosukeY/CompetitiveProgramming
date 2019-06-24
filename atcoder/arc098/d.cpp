#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
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
  SegmentTree(ll _n, T e, Operator op, Apply apply): e(e), op(op), apply(apply) {
    for(n = 1; n < _n; n *= 2);
    data.resize(n * 2 - 1, e);
  }

  // construct with initial values
  SegmentTree(const vector<T> &vec, T e, Operator op, Apply apply): e(e), op(op), apply(apply) {
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

main(){
  int n; cin >> n;

  auto op1 = [](int a, int b){ return a ^ b; };
  auto op2 = [](int a, int b){ return a + b; };
  auto app = [](int a, int b){ return b; };
  SegmentTree<int, int> segtree1(n, 0, op1, app);
  SegmentTree<int, int> segtree2(n, 0, op2, app);

  vi a(n);
  rep(i,n){
    cin >> a[i];
    segtree1.update(i,a[i]);
    segtree2.update(i,a[i]);
  }
  dump(segtree1.data,segtree2.data);
  int l = 0, r = 1; // [l, r)
  int ans = 0;
  while(1){
    dump(l,r);
    if(segtree1.query(l, r) == segtree2.query(l, r)){
      r++;
      ans++;
    }else{
      while(segtree1.query(l+1,r) != segtree2.query(l+1,r))
	l++;
      l++;
    }
    if(r > n) break;
    cout << ans << endl;
  }
  ans += (r - l - 1) * (r - l - 2) / 2;
  cout << ans << endl;
}
