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

vi dx = {0, 1, 1}, dy = {1, 0, 1};

main()
{
  int h,w; cin >> h >> w;
  vs s(h); rep(i,h) cin >> s[i];

  vvi cost(h,vi(w,inf));
  rep(i,h) rep(j,w) if(s[i][j] == '#') cost[i][j] = -1;
  cost[0][0] = 0;

  queue<pii> q;
  q.push(pii(0,0));
  while(not q.empty()){
    pii p = q.front();
    q.pop();
    rep(i,sz(dx)){
      pii next;
      next.fst = p.fst + dx[i];
      next.snd = p.snd + dy[i];
      if(next.fst < h and next.snd < w and cost[next.fst][next.snd] == inf){
	cost[next.fst][next.snd] = cost[p.fst][p.snd] + 1;
	q.push(next);
      }
    }
  }
  rep(i,h){
    rep(j,w){
      if(cost[i][j] == inf) cout << "x";
      else cout << cost[i][j];
    }
    cout << endl;
  }
}
