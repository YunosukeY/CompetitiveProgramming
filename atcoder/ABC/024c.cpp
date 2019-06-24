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
typedef long long ll;
#define inf 999999999 

main(){
  int n,d,k; cin >> n >> d >> k;
  vi l(d),r(d); rep(i,d) cin >> l[i] >> r[i];
  rep(i,k){
    int s,t; cin >> s >> t;
    if(s<=t){
      rep(j,d){
	if(l[j] <= s and s <= r[j]) s = r[j];
	//cout << s << endl;
	if(t <= s){
	  cout << j+1 << endl;
	  break;
	}	
      }
    }else{
      rep(j,d){
	if(l[j] <= s and s <= r[j]) s = l[j];
	if(s <= t){
	  cout <<j+1 << endl;
	  break;
	}
      }
    }
  }
}
