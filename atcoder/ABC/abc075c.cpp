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

int n;

bool dfs(vvi adj){
  vi check(n);
  stack<int> st;
  st.push(0);
  check[0] = 1;

  while(!st.empty()){
    int tmp = st.top();
    st.pop();
    rep(i,n) if(adj[tmp][i] == 1 and check[i] == 0){
      check[i] = 1;
      st.push(i);
    }
  }
  rep(i,n) if(check[i] == 0) return true; // 不連結
  return false;
}

main(){
  int m; cin >> n >> m;
  vvi adj(n,vi(n));
  int a, b;
  rep(i,m){
    cin >> a >> b;
    adj[a-1][b-1] = adj[b-1][a-1] = 1;
  }
  int ans = 0;
  rep(i,n) rep(j,n) if(adj[i][j] == 1){
    adj[i][j] = adj[j][i] = 0;
    if(dfs(adj)){
      //printf("(%d,%d)\n",i,j);
      ans++;
    }
    adj[i][j] = adj[j][i] = 1;
  }
  cout << ans / 2 << endl;
}
