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
  int n,h; cin >> n >> h;
  vi a(n),b(n);
  int maxai=0,maxbi,i;
  rep(j,n){
    cin >> a[j] >> b[j];
    if(a[j] > maxai){
      maxai = a[j];
      i = j;
      maxbi = b[j];
    }
  }
  sort(all(b));
  int count = 0;
  int j = n-1;
  while(1){
    //cout << h << endl;
    if(h <= 0){
      cout << count << endl;
      break;
    }
    if(b[j] > maxai){//投げる
      h -= b[j];
      j--;
      count++;
    }else{//投げるより切る
      h -= maxai;
      count++;
    }
  }
}
