#include<bits/stdc++.h>
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

constexpr int inf = 1ll<<62;
constexpr int mod = 1e9+7;

main(){
  int n,m; cin >> n >> m;
  string s; cin >> s;
  vvi g(n);
  rep(i,m){
    int a,b; cin >> a >> b; a--; b--;
    if(count(all(g[a]),b) == 0)
      g[a].pb(b);
    if(count(all(g[b]),a) == 0)
      g[b].pb(a);
  }

  vi anum(n),bnum(n); // 隣接するA,Bの数
  rep(i,n) rep(j,g[i].size()){
    if(s[ g[i][j] ] == 'A') anum[i]++;
    else bnum[i]++;
  }

  vi used(n);
  rep(i,n){
    if(used[i] == 0 and anum[i] * bnum[i] == 0){
      used[i] = 1;
      queue<int> q;
      q.push(i);

      while(!q.empty()){
	int now = q.front();
	q.pop();

	rep(j,g[now].size()){
	  int next = g[now][j];
	  if(s[now] == 'A') anum[next]--;
	  else bnum[next]--;
	  
	  if(used[next] == 0 and anum[next]*bnum[next] == 0){
	    used[next] = 1;
	    q.push(next);
	  }
	}
      }
    }
    dump(used,anum,bnum);
  }
  if(accumulate(all(used),0ll) == n) cout << "No\n";
  else cout << "Yes\n";
}
