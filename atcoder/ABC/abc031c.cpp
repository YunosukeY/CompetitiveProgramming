#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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

main(){
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];

  //rep(i,n) cout << a[i];
  
  int maxtakahashi = -(1<<29);
  rep(i,n){
    int maxaoki = -(1<<29), tmp = -(1<<29);
    rep(j,n){
      if(i == j) continue;
      int h = min(i,j), t = max(i,j);
      int takahashi = 0, aoki = 0;
      FOR(k,h,t) if((k-h+1) % 2 == 0) aoki += a[k]; else takahashi += a[k];
      if(maxaoki < aoki){
	maxaoki = aoki;
	tmp = takahashi;
      }
    }
    maxtakahashi = max(maxtakahashi,tmp);
  }
  cout << maxtakahashi << endl;
}
