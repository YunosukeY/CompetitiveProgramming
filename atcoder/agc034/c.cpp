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

int n, x;
vi b, l, u;
vi pos;
vector<int> imos;
auto f = [&](int i){
  return b[i]*l[i]+(x-b[i])*u[i];
};

bool solve(int k){ // 合計がkの時に勝てるか
  int q = k / x, r = k - q * x; // q個をx点に、1つをr点に、残りを0点に
  rep(i,n){ // どのpos[i]をrにするか全探索
    int d;
    int j = pos[i];
    if(i < q) d = imos[q+1] - f(j);
    else d = imos[q];
    dump(d);
    d += min(r,b[j])*l[j];
    d += min(max(0ll,r-b[j]),x-b[j])*u[j];
    dump(d);
    if(d >= 0) return true;
  }
  return false;
}

int bs(int _ok, int _ng){
  int ok = _ok;
  int ng = _ng;

  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;
    if(solve(mid)){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  return ok;
}

signed main(){
  cin >> n >> x;
  b.resize(n), l.resize(n), u.resize(n);
  pos.resize(n);
  imos.resize(n+1);
  iota(all(pos),0);
  rep(i,n) cin >> b[i] >> l[i] >> u[i];
  auto g = [&](int i, int j){
    return f(i) > f(j);
  };
  sort(all(pos),g);
  rep(i,n) imos[i+1] += imos[i] + f(pos[i]);
  dump(pos, imos);
  cout << bs(n*x,0) << endl;
}
