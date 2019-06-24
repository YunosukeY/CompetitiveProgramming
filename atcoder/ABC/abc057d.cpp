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
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){
  int n,a,b; cin >> n >> a >> b;
  vll v(n); rep(i,n) cin >> v[i];

  sort(rall(v));
  double ave = (double)accumulate(v.begin(),v.begin()+a,0ll) / a;
  printf("%.10f\n",ave);

  int x = 0; rep(i,n) if(v[a-1] == v[i]) x++;

  vector<vector<ll>> C(x+1);
  C[0].pb(1);
  FOR(i,1,x+1){
    C[i].resize(i+1);
    rep(j,i) rep(k,2)
      C[i][j+k] += C[i-1][j];
  }
  showvv(C);

  if(v[0] != v[a-1]){
    int y = 0; rep(i,a) if(v[a-1] == v[i]) y++;
    cout << C[x][y] << endl;
  }else{
    ll ans = 0;
    FOR(i,a,min(x+1,b+1)) ans += C[x][i];
    cout << ans << endl;
  }
}
