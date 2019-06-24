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

main(){
  int n,t; cin >> n >> t;
  int minv = 1 << 29, maxdiff = -(1 << 29), c = 0;

  rep(i,n){
    int a; cin >> a;
    minv = min(minv, a);
    if(a - minv == maxdiff) c++;
    else if(a - minv > maxdiff){
      maxdiff = a - minv;
      c = 1;
    }
  }

  cout << c << endl;
}
