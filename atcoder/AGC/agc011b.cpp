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

#define int ll

const int inf = 1ll<<62;
const int mod = 1e9+7;

main()
{
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  sort(all(a));

  // 累積和 = 自分以下のものを全て食べた時の大きさ
  vi b = a;
  rep(i,n-1) b[i+1] += b[i];
  dump(a,b);
  
  int ans = 1; // 最大値のものは必ず生き残る
  ROF(i,n-1,0)
    if(2 * b[i] >= a[i+1]) ans++; // 自分の次に大きい物を食べれる
    else break; // 無理ならそれより小さいものも無理

  cout << ans << endl;
}
