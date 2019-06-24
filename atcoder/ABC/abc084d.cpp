#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
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

int main(){
#define int ll
  vi like(100001,1);
  like[0] = 0; like[1] = 0;
  // 素数を残す
  FOR(i,2,sz(like))
    if(like[i])
      for(ll j = 2 * i; j < sz(like); j += i)
	like[j] = 0;
  // (n + 1) / 2も素数のものを残す
  ROF(i,sz(like),0)
    like[i] = like[i] * like[(i+1)/2];

  // 累積和を求める
  rep(i,sz(like)-1) like[i+1]+= like[i];

  int q; cin >> q;
  rep(i,q){
    int l,r; cin >> l >> r;
    cout << like[r] - like[l-1] << endl;
  }
}
