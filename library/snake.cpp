#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
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

int main(){
#define int ll
  int h,w; cin >> h >> w;
  vvi a(h,vi(w));

  // snake A
  // >>>>>v
  // v<<<<<
  // >>>>>v
  // v<<<<<
  // >>>>>x
  //
  // rep(i,h)
  //   if(i & 1){
  //     ROF(j,w,1) dump(i,j); // < * w-1
  //     dump(i,0);            // v
  //   }else{
  //     rep(j,w-1) dump(i,j); // > * w-1
  //     dump(i,w-1);          // v
  //   }

  // snake B
  // >>>>>v
  //      v
  // v<<<<<
  // v
  // >>>>>x
  //
  // for(ll i=0,i_cond=h;i<i_cond;i+=2)
  //   if(i & 2){
  //     ROF(j,w,1) dump(i,j);             // ← × w-1
  //     rep(k,min(2ll,h-i)) dump(i+k,0)   // ↓ × 1or2
  //   }else{
  //     rep(j,w-1) dump(i,j);             // →  × w-1
  //     rep(k,min(2ll,h-i)) dump(i+k,w-1) // ↓ × 1or2
  //   }

  // snake A tail > head
  // >>>>>>v
  // xv<<<<<
  // ^>>>>>v
  // ^v<<<<<
  // ^>>>>>v
  // ^<<<<<<
  //
  // assert(~(h&1) and w >= 2);  // 縦偶数かつ横2以上
  // dump(0,0);                  // →
  // rep(i,h)
  //   if(i & 1){
  //     ROF(j,w,2) dump(i,j);   // ← × w-2
  //     dump(i,1);              // ↓
  //   }else{
  //     FOR(j,1,w-1) dump(i,j); // → × w-2
  //     dump(i,w-1);            // ↓
  //   }
  // ROF(i,h,1) dump(i,0);       // ↑ × h-1


  // snake B tail > head
  
}
