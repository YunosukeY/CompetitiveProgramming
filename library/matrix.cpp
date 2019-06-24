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

template<class T>
class mat{
public:
  int n, m;
  vector<vector<T>> a;

  mat(int n_, T k):n(n_),m(n_){
    a.resize(n);
    rep(i,n){
      a[i].resize(m);
      a[i][i] = k;
    }
  }
  
  mat(int n_, int m_, T k):n(n_),m(m_){
    a.resize(n);
    rep(i,n) a[i].resize(m,k);
  }

  mat(const vector<vector<int>> &a_){
    n = a_.size();
    assert(n > 0);
    m = a_[0].size();
    assert(m > 0);
    rep(i,n) assert(m == sz(a_[i]));
    a  = a_;
  }
};

template<class T>
mat<T> operator*(const mat<T> &A, const mat<T> &B){
  assert(A.m == B.n);
  mat<T> C(A.n, B.m, T(0));
  rep(i,C.n) rep(j,C.m) rep(k,A.m)
    C.a[i][j] += A.a[i][k] * B.a[k][j];
  return C;
}

template<class T>
ostream& operator<<(ostream &os, const mat<T> &A){
  os << A.a;
  return os;
}

signed main(){
  mat<int> a(10,5);
  mat<int> b(10,10,2);
  cout << a*b << endl;;

  vvi c(10, vi(10,2));
  mat<int> d(c);
  cout << a*d << endl;
}
