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
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

  rep(i,tx-sx) printf("R");
  rep(i,ty-sy) printf("U");
  rep(i,tx-sx) printf("L");
  rep(i,ty-sy) printf("D");

  printf("D");
  rep(i,tx-sx+1) printf("R");
  rep(i,ty-sy+1) printf("U");
  printf("L");
  printf("U");
  rep(i,tx-sx+1) printf("L");
  rep(i,ty-sy+1) printf("D");
  printf("R");
  printf("\n");
}
