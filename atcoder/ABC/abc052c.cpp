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

vector<pii> prime(int n){ // n以下の素数を要素に持つviを返す
  vector<bool> isprime(n+1,true);
  vector<pii> ans;
  isprime[0] = isprime[1] = false;
  FOR(i,2,n+1)
    if(isprime[i]){
      ans.pb(pii(i,0));
      for(int j = 2 * i; j <= n; j += i) isprime[j] = false;
    }
  return ans;
}


main(){
  int n; cin >> n;
  ll ans = 1;
  vector<pii> p = prime(n);

  FOR(i,2,n+1) rep(j,p.size()){
    int x = i;
    while(1){
      if(x % p[j].fst == 0){
	p[j].snd++;
	x /= p[j].fst;
      }else break;
    }
  }
  
  rep(i,p.size()){
    //cout << p[i].fst << " " << p[i].snd << endl;
    ans *= p[i].snd + 1;
    ans %= 1000000007;
  }
  cout << ans << endl;
}
