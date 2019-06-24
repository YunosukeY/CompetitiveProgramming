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

signed main(){
  int n, k; cin >> n >> k;
  vi v(n); rep(i,n) cin >> v[i];

  vi imos(n+1);
  rep(i,n){
    imos[i+1] = imos[i] + v[i];
  }
  dump(imos);
  int ans = 0;
  FOR(i,1,min(k+1,n+1)){ // i個取る
    rep(j,i+1){ // 左からj個取る
      int tmp = imos[j]-imos[0]+imos[n]-imos[n-(i-j)];
      priority_queue<int> q;
      rep(l,j){
	if(v[l] < 0) q.push(v[l]);
      }
      FOR(l,n-(i-j),n){
	if(v[l] < 0) q.push(v[l]);
      }
      while(q.size() > k-i) q.pop();
      while(!q.empty()){
	tmp -= q.top();
	q.pop();
      }
      chmax(ans,tmp);
    }
  }
  cout << ans << endl;
}
