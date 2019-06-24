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

int main(){
  string s; cin >> s;
  int sz = s.size();
  int x,y; cin >> x >> y;

  // d
  vi d;
  int pos = 0;
  d.pb(0);
  while(pos < sz){
    if(s[pos] == 'T'){
      pos++;
      d.pb(0);
    }else{
      int tmp = 0;
      while(s[pos] == 'F'){
	pos++;
	tmp++;
      }
      d.back() += tmp;
    }
  }

  vvi dpx((d.size()+1)/2, vi(2*sz+1)), dpy(d.size()/2, vi(2*sz+1)); // 原点がsz
  // xのdp
  dpx[0][d[0]+sz] = true;
  int i = 2;
  while(i < d.size()){
    rep(j,2*sz+1){
      if(j - d[i] >= 0)
	dpx[i/2][j] |= dpx[i/2 - 1][j - d[i]];
      if(j + d[i] <= 2*sz)
	dpx[i/2][j] |= dpx[i/2 - 1][j + d[i]];
    }
    i += 2;
  }

  // yのdp
  if(d.size() >= 2)
    dpy[0][d[1]+sz] = dpy[0][-d[1]+sz] = true;
  i = 3;
  while(i < d.size()){
    rep(j,2*sz+1){
      if(j - d[i] >= 0)
	dpy[i/2][j] |= dpy[i/2 - 1][j - d[i]];
      if(j + d[i] <= 2*sz)
	dpy[i/2][j] |= dpy[i/2 - 1][j + d[i]];
    }
    i += 2;
  }
  dump(d,dpx,dpy);

  int f = dpx[(d.size()-1)/2][x+sz];
  if(d.size() >= 2) f &= dpy[d.size()/2 - 1][y+sz];
  else f &= (y == 0);
  if(f)
    cout << "Yes\n";
  else
    cout << "No\n";
}
