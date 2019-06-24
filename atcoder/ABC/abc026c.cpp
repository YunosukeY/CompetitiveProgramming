#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
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

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vvi down;

int calc(int n){
  if(down[n].size() == 0) return 1;

  int minv = 1 << 29, maxv = 0;
  rep(i,down[n].size()){
    int c = calc(down[n][i]);
    minv = min(minv,c);
    maxv = max(maxv,c);
  }
  return minv + maxv + 1;
}

main(){
  int n; cin >> n;
  down.resize(n);
  vi b(n-1);
  rep(i,n-1){
    cin >> b[i];
    down[--b[i]].pb(i+1);
  }
  //rep(i,n) {rep(j,down[i].size()) cout << down[i][j]; cout << endl;}

  cout << calc(0) << endl;
}
