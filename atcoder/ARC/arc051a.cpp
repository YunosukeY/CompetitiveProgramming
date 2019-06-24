#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
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

int cx,cy,r;

bool isinc(pii p){
  if(pow(cx - p.fst, 2) + pow(cy - p.snd, 2) <= pow(r, 2)) return true;
  else return false;
}

int lx,ly,rx,ry;

bool isins(pii p){
  if(lx <= p.fst and p.fst <= rx and ly <= p.snd and p.snd <= ry) return true;
  else return false;
}

main(){
  cin >> cx >> cy >> r >> lx >> ly >> rx >> ry;
  vector<pii> c(4),s(4);

  c[0] = pii(cx + r, cy);
  c[1] = pii(cx, cy + r);
  c[2] = pii(cx - r, cy);
  c[3] = pii(cx, cy - r);

  s[0] = pii(lx, ly);
  s[1] = pii(lx, ry);
  s[2] = pii(rx, ly);
  s[3] = pii(rx, ry);

  bool f;

  f = false;
  rep(i,4) if(not isins(c[i])) f = true;
  if(f) cout << "YES\n";
  else cout << "NO\n";

  f = false;
  rep(i,4) if(not isinc(s[i])) f = true;
  if(f) cout << "YES\n";
  else cout << "NO\n";

}
