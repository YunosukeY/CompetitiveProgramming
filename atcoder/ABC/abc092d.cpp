#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#define showvv(v)
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

int main(){
  int a,b; cin >> a >> b; a--; b--;
  
  char ans[100][100];
  rep(i,50) rep(j,100) ans[i][j] = '#';
  FOR(i,50,100) rep(j,100) ans[i][j] = '.';
  
  int x = 0,y = 0;
  while(a > 0){
    a--;
    ans[x][y] = '.';
    y += 2;
    if(y >= 100){
      y = 0;
      x += 2;
    }
  }

  x = 99; y = 0;
  while(b > 0){
    b--;
    ans[x][y] = '#';
    y += 2;
    if(y >= 100){
      y = 0;
      x -= 2;
    }
  }

  cout << "100 100\n";
  rep(i,100){
    rep(j,100) cout << ans[i][j];
    cout << endl;
  }
}
