#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) ((a).begin(),(a).end())
#define rall(a) ((a).rbegin(),(a).rend()) //sortで大きい順
#define UNIQUE(v) (v.erase(unique(all(v)),v.end()))
#define SUM(a) (accumulate(all(a),0))
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  int n,m; cin >> n >> m;
  vvi cost(n, vi(n,1<<29) ),isedge(n,vi(n));

  rep(i,m){
    int a,b,c; cin >> a >> b >> c; a--; b--;
    cost[a][b] = cost[b][a] = c;
    isedge[a][b] = isedge[b][a] = true;
  }

  int ans = 0;
  rep(k,n) rep(i,n) rep(j,n)
    if(cost[i][j] > cost[i][k] + cost[k][j]){
      cost[i][j] = cost[i][k] + cost[k][j];
      if(isedge[i][j] == true){
	isedge[i][j] = isedge[j][i] = false;
	ans++;
      }
    }

  cout << ans << endl;
}
