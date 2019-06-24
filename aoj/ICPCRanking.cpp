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

main()
{
  while(1){
    int M,T,P,R; cin >> M >> T >> P >> R;
    if(M == 0) break;
    vvi problem(T,vi(P)); // どのチームがどの問題に何回不正解か
    vector<pair<pii,int>> team(T); // 正答数、所要時間合計、チーム番号
    rep(i,T) team[i].snd = i + 1; // 本当はi+1
    rep(i,R){
      int m,t,p,j; cin >> m >> t >> p >> j; t--; p--;
      if(j) problem[t][p]++;
      else{
	team[t].fst.fst++;
	team[t].fst.snd -= m + 20 * problem[t][p];
      }
    }
    sort(rall(team));
    cout << team[0].snd;
    rep(i,T-1){
      if(team[i].fst.fst == team[i+1].fst.fst and team[i].fst.snd == team[i+1].fst.snd) cout << "=";
      else cout << ",";
      cout << team[i+1].snd;
    }
    cout << endl;
    //dump(team);
  }	    
}
