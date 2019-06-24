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
  ll h, w; cin >> h >> w;
  ll a,b,c;
  ll ans = 1ll << 60;
  ll smax,smin,tmp;
  
  FOR(i,1,h){
    a = i * w;
    tmp = (h - i) / 2;
    b = tmp * w;
    c = (h - i - tmp) * w;
    if(a !=0 and b != 0 and c != 0){
      smax = max(a,max(b,c));
      smin = min(a,min(b,c));
      if(ans > smax - smin){
	ans = min(ans,smax-smin);
      }
    }

    tmp = w / 2;
    b = (h - i) * tmp;
    c = (h - i) * (w - tmp);
    if(a !=0 and b != 0 and c != 0){
      smax = max(a,max(b,c));
      smin = min(a,min(b,c));
      if(ans > smax - smin){
	ans = min(ans,smax-smin);
      }
    }
  }
  swap(h,w);
  FOR(i,1,h){
    a = i * w;
    tmp = (h - i) / 2;
    b = tmp * w;
    c = (h - i - tmp) * w;
    if(a !=0 and b != 0 and c != 0){
      smax = max(a,max(b,c));
      smin = min(a,min(b,c));
      if(ans > smax - smin){
	ans = min(ans,smax-smin);
      }
    }

    tmp = w / 2;
    b = (h - i) * tmp;
    c = (h - i) * (w - tmp);
    if(a !=0 and b != 0 and c != 0){
      smax = max(a,max(b,c));
      smin = min(a,min(b,c));
      if(ans > smax - smin){
	ans = min(ans,smax-smin);
      }
    }
  }
  cout << ans << endl;
}
