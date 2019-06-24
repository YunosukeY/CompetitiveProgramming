#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n; cin >> n;
  vi c(n-1),s(n-1),f(n-1);
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];

  rep(i,n){//start
    int time = 0;
    FOR(j,i,n-1){
      if(time < s[j]) time = s[j];
      else if(time % f[j] == 0);
      else time = time + f[j] - (time%f[j]);
      time += c[j];
    }
    cout << time << endl;
  }
}
