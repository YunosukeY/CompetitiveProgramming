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

main(){
  int w,h,n; cin >> w >> h >> n;
  int x,y,a;
  vi data(4);
  data[1]=w;
  data[3]=h;

  rep(i,n){
    cin >> x >> y >> a;
    a--;
    if(a == 0 && data[0] < x) data[0] = x;
    else if(a == 1 && x < data[1]) data[1] = x;
    else if(a == 2 && data[2] < y) data[2] = y;
    else if(a == 3 && y < data[3]) data[3] = y;
  }

  int ans = 0;
  if(data[1] > data[0] && data[3] > data[2]) ans = (data[1] - data[0]) * (data[3] - data[2]);
  cout << ans << endl;
}
