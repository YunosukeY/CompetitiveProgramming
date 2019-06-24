#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n, m; cin >> n >> m;
  vvi adj(n,vi(n));
  int a, b;
  rep(i,m){
    cin >> a >> b;
    a--; b--;
    adj[a][b] = adj[b][a] = 1;
  }

  vi path(n-1);
  iota(all(path),1);
  int prev, ans = 0;
  bool f;
  do{
    f = true;
    prev = 0;
    rep(i,path.size())
      if(adj[prev][path[i]] == 1) prev = path[i];
      else f = false;
    if(f){
      ans++;
    }
  }while(next_permutation(all(path)));
  cout << ans << endl;
}
