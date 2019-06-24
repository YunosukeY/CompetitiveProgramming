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

int main(){
  int n; cin >> n;
  string s; cin >> s;

  rep(i,2) rep(j,2){ // 0ならS,1ならW
    vi a(n); a[0] = i; a[1] = j;
    rep(k,n-2){
      if(a[k+1] == 0)
	if(s[k+1] == 'o') a[k+2] = a[k];
	else a[k+2] = not a[k];
      else
	if(s[k+1] == 'x') a[k+2] = a[k];
	else a[k+2] = not a[k];
    }
    bool f = false;
    if(a[n-1] == 0)
      if(s[n-1] == 'o' and a[n-2] == a[0]) f = true;
      else if(s[n-1] == 'x' and a[n-2] != a[0]) f = true;
      else ;
    else
      if(s[n-1] == 'o' and a[n-2] != a[0]) f = true;
      else if(s[n-1] == 'x' and a[n-2] == a[0]) f = true;
      else ;

    if(not f) continue;
    f = false;
    if(a[0] == 0)
      if(s[0] == 'o' and a[n-1] == a[1]) f = true;
      else if(s[0] == 'x' and a[n-1] != a[1]) f = true;
      else ;
    else
      if(s[0] == 'o' and a[n-1] != a[1]) f = true;
      else if(s[0] == 'x' and a[n-1] == a[1]) f = true;
      else ;

    if(f){
      rep(i,n)
	if(a[i] == 0) cout << "S";
	else cout << "W";
      cout << endl;
      return 0;
    }
  }
  cout << "-1\n";
}
