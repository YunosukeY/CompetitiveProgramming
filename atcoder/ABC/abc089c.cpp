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

main(){
  int n; cin >> n;
  ll m=0,a=0,r=0,c=0,h=0;
  string s;
  rep(i,n){
    cin >> s;
    if(s[0] == 'M') m++;
    else if(s[0] == 'A') a++;
    else if(s[0] == 'R') r++;
    else if(s[0] == 'C') c++;
    else if(s[0] == 'H') h++;
  }
  ll ans = 0;
  ans += m * a * r;
  ans += m * a * c;
  ans += m * a * h;
  
  ans += m * r * c;
  ans += m * r * h;

  ans += m * c * h;

  ans += a * r * c;
  ans += a * r * h;
  
  ans += a * c * h;
  
  ans += r * c * h;

  cout << ans << endl;
}
