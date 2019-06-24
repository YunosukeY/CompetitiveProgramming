#include<bits/stdc++.h>
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

main(){
  int h,w,n; cin >> h >> w >> n;
  map<pii,int> mp; // (x,y)を左上とする正方形が何回出るか

  rep(k,n){
    int a,b; cin >> a >> b;

    rep(i,3) rep(j,3){
      int x = a - i, y = b - j; // 影響のある正方形が
      if(1 <= x and x <= h - 2 and 1 <= y and y <= w - 2){ // はみ出ていないなら
	mp[pii(x,y)]++;
      }
    }
  }

  vi ans(9);
  for(auto x : mp){
    //cout << x.fst.fst << " " << x.fst.snd << " " << x.snd << endl;
    ans[x.snd-1]++;
  }

  cout << (ll)(h - 2) * (w - 2) - SUM(ans) << endl;
  rep(i,9) cout << ans[i] << endl;
}
