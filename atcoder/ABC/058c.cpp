#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n,k; cin >> n >> k;
  vi d(k); rep(i,k) cin >> d[i];

  while(1){
    int x = n;
    //cout << n << endl;
    while(1){
      bool flag = false;
      //cout << x % 10 << endl;
      //1番下の桁を検査
      rep(i,k){
	if(not (d[i] == (x % 10))) continue;
	else{
	  flag = true;//ダメな数字があれば
	  break;
	}
      }
      //cout << flag << endl;
      if(flag) break;//次を調べる
      x /= 10;
      //cout << x << endl;
      if(x == 0){
	cout << n << endl;
	return 0;
      }
    }
    n++;
    //if(n == 1010) break;
  }

}
