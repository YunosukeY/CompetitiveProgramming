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

ll f(ll b, ll n){
  if(n < b) return n;
  else return f(b, n / b) + (n % b);
}

main(){
  ll n,s; cin >> n >> s;

  if(n == s){
    cout << n + 1 << endl;
    return 0;
  }

  ll m = sqrt(n);

  for(ll i = 2; i <= m + 1; i++){
    if(f(i, n) == s){
      cout << i << endl;
      return 0;
    }
  }

  for(ll i = m - 1; i > 0; i--){
    ll b = (n - s) / i + 1;
    if(b < 2) continue;
    if(f(b, n) == s){
      cout << b << endl;
      return 0;
    }
  }

  cout << "-1\n";
}
