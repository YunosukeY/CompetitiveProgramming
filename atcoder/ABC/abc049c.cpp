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
  string s; cin >> s;
  bool ans;

  int i = s.size();
  while(i >= 5){
    if(i - 5 >= 0)
      if(s.substr(i-5,5) == "dream"){
	i -= 5;
	continue;
      }else if(s.substr(i-5,5) == "erase"){
	i -= 5;
	continue;
      }
    if(i - 6 >= 0 and s.substr(i-6,6) == "eraser"){
      i -= 6;
      continue;
    }
    if(i - 7 >= 0 and s.substr(i-7,7) == "dreamer"){
      i -= 7;
      continue;
    }
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
}
