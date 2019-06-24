#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
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

main()
{
  string now; cin >> now;
  string before;

  // now中の"ABC"を元に合った文字に入れ替える
  while(now != "ABC"){
    before = now; // 変更前を記録

    vi abcpos; // "ABC"がある位置を記録
    rep(i,sz(now) - 2) if(now.substr(i,3) == "ABC") abcpos.pb(i);
    dump(abcpos);

    vi abcused(3); // A,B,Cがabcpos以外で使われているか判定
    rep(i,sz(now)){
      if(i < i_cond - 2 and now.substr(i,3) == "ABC") i += 2;
      else abcused[now[i] - 'A'] = 1;
    }
    dump(abcused);
    if(SUM(abcused) != 2) break; // 2種類でなければおかしい
    string lostchar; // 残りの1種類を格納
    rep(i,3) if(abcused[i] == 0) lostchar = char('A' + i);
    dump(lostchar);

    // 後ろから"ABC"を消して代わりにlostcharを挿入
    reverse(all(abcpos));
    rep(i,sz(abcpos)){
      now.erase(abcpos[i],3);
      now.insert(abcpos[i],lostchar);
    }
    
    if(before == now) break; // 変わっていなければおかしい
    dump(now);
  }

  if(now == "ABC") cout << "Yes\n";
  else cout << "No\n";
}
