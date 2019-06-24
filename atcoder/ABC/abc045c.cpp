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

ll ans;
string s;

void rec(int n,vector<bool> op){
  if(n == op.size()){
    int l = 0, r = 0;
    while(r < op.size()){
      if(op[r] == false){
	r++;
      }else{
	ans += stoll(s.substr(l,r-l+1));
	//cout << ans << endl;
	l = r = r + 1;
      }
    }
    ans += stoll(s.substr(l,r-l+1));
    //cout << "(" << l << "." << r << ")" << endl;
  }else{
    rec(n+1,op);
    op[n] = true;
    rec(n+1,op);
  }
}
  

main(){
  cin >> s;
  vector<bool> op(s.size()-1);
  ans = 0;
  rec(0,op);
  cout << ans << endl;
}
