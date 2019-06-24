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
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int h,w;

void next(int &x, int &y){
  if(x % 2 == 0) y++;
  else y--;
  if(y == w){ x++; y--; }
  if(y == -1){ x++; y++; }
}

int main(){
  int n; cin >> h >> w >> n;
  vvi c(h,vi(w));

  int x = 0, y = 0;
  rep(k,n){
    int a; cin >> a;
    while(a){
      c[x][y] = k + 1;
      next(x,y);
      a--;
    }
  }
  dump(h,w,c);
  rep(i,h){
    rep(j,w-1) cout << c[i][j] << " ";
    cout << c[i][w-1] << endl;
  }
}
