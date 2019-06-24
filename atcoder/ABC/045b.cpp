#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define mod 1000000007;

main(){
  string a,b,c; cin >> a >> b >> c;
  int x=1,y=0,z=0;//次に出すカード
  char now = a[0];
  while(1){
    if(now == 'a'){
      if(x == a.size()){
	cout << 'A' << endl;
	break;
      }else{
	now = a[x];
	x++;
      }
    }else if(now == 'b'){
      if(y == b.size()){
	cout << 'B' << endl;
	break;
      }else{
	now = b[y];
	y++;
      }
    }else if(now == 'c'){
      if(z == c.size()){
	cout << 'C' << endl;
	break;
      }else{
	now = c[z];
	z++;
      }
    }
  }
}
