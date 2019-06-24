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

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

main(){
  string s; cin >> s;
  int ans = 0;
  int prev = 0, next;
  bool last = false;
  while(1){
    next = s.find("+",prev);
    if(next == -1){
      next = s.size();
      last = true;
    }
    bool flag = false;
    FOR(i,prev,next){
      if(s[i] == '0') flag = true;
    }
    if(not flag) ans++;
    if(last) break;
    prev = next + 1;
  }
  cout << ans << endl;
}
