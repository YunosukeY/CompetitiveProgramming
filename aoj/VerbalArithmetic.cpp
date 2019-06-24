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

#define int ll

template <class BI>
bool next_partial_permutation(BI first, BI middle, BI last) {
  reverse(middle, last);
  return next_permutation(first, last);
}

main()
{
  while(1){
    int n; cin >> n; if(n == 0) break;
    vs s(n); rep(i,n) cin >> s[i];
    set<char> st;
    rep(i,n) rep(j,sz(s[i])) st.insert(s[i][j]);
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int ans = 0;
    // 全探索
    do{
      // 変換関数
      map<char,int> f;
      int k = 0;
      for(auto x : st){
	f[x] = a[k];
	k++;
      }
      vs t = s;

      // 変換
      rep(i,n) rep(j,sz(t[i])) t[i][j] = f[s[i][j]] + '0';
      bool ok = true;
      rep(i,n) if(sz(t[i]) > 1 and t[i][0] == '0') ok = false;
      if(not ok) continue;

      int sum = 0;
      rep(i,n-1) sum += stoi(t[i]);
      if(sum == stoi(t[n-1])) ans++;
    }while(next_partial_permutation(a,a+sz(st),a+10));
    cout << ans << endl;
  }
}
