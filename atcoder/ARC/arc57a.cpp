#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
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

ll a, k;

ll calc(ll n){
  ll diff = 0, res = 0;
  ll tmp = 1;
  for(ll i = 0; i < n; i++){
    diff += tmp;
    res += diff;
    tmp *= k;
  }
  diff += tmp * a;
  res += diff;
  return res;
}

main(){
  cin >> a >> k;

  rep(i,4)
    cout << calc(i) << endl;
}
