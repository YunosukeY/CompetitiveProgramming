#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
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
  ll n; cin >> n;
  ll phase = 0, num = 1, depth = 0;
  for(ll i  = n; i > 0; i/=2) depth++;
  //cout << depth << endl;
  
  if(depth%2 == 0){
    while(1){
      if(phase % 2 == 0) num = num * 2;
      else num = num * 2 + 1;
      if(num > n){
	if(phase % 2 == 0) cout << "Aoki\n";
	else cout << "Takahashi\n";
	return 0;
      }
      phase++;
    }
  }else{
    while(1){
      if(phase % 2 == 0) num = num * 2 + 1;
      else num = num * 2;
      if(num > n){
	if(phase % 2 == 0) cout << "Aoki\n";
	else cout << "Takahashi\n";
	return 0;
      }
      phase++;
    }
  }
}
