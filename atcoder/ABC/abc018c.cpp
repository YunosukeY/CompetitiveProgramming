#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int r,c,k; cin >> r >> c >> k;
  vs s(r); rep(i,r) cin >> s[i];

  auto updown = vector<vector<pii>>(r,vector<pii>(c,pii(0,0)));

  rep(i,r) rep(j,c){
    //up
    ROF(k,i,0)
      if(s[k][j] == 'o') updown[i][j].first++;
      else break;
    //down
    FOR(k,i,r)
      if(s[k][j] == 'o') updown[i][j].second++;
      else break;
  }
  /*
  rep(i,r){
    rep(j,c) cout << updown[i][j].first << "/" << updown[i][j].second << " ";
    cout << endl;
  }
  */

  int ans = 0;

  FOR(x,k-1,r-k+1) FOR(y,k-1,c-k+1){
    bool flag = true;
    FOR(j,-(k-1),k)
      if((updown[x][y+j].first >= k-abs(j)) and (updown[x][y+j].second >= k-abs(j)))
	continue;
      else{ flag = false; break;}
    if(flag){
      ans++;
      //cout << x << " " << y << endl;
    }
  }
  cout << ans << endl;
}
