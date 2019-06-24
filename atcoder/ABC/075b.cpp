#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int h,w; cin >> h >> w;
  vs s(h); rep(i,h) cin >> s[i];
  int dx[8]={1,0,-1,0,1,-1,-1,1};
  int dy[8]={0,1,0,-1,1,1,-1,-1};
  int x,y;
  int count;

  rep(i,h) rep(j,w){
    if(s[i][j]=='#') continue;
    count = 0;
    rep(k,8){
      x = j + dx[k];
      y = i + dy[k];
      //cout << x << " " << y << endl;
      if(x<0 || w<=x) continue;
      if(y<0 || h<=y) continue;
      if(s[y][x]=='#') count++;
    }
    //cout << count << endl;
    s[i][j]=(char)(count+'0');
  }
  rep(i,h) cout << s[i] << endl;;
}
