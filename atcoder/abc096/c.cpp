#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define int ll

int h,w;
vs s;
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

bool search(int x, int y){
  bool f = false;
  
  rep(i,sz(dx)){
    int nx = x + dx[i], ny = y + dy[i];
    if(0 <= nx and nx < h and 0 <= ny and ny < w and s[nx][ny] == '#'){
      s[nx][ny] = '.';
      f = true;
      search(nx, ny);
    }
  }

  return f;
}


main()
{
  cin >> h >> w;
  s.resize(h);
  rep(i,h) cin >> s[i];

  rep(i,h) rep(j,w){
    if(s[i][j] == '#'){
      s[i][j] = '.';
      if(search(i,j) == false){
	cout << "No\n";
	return 0;
      }
    }
  }
  dump(s);
  cout << "Yes\n";
}
