#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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
ll mod = 1000000007;

ll powmod(ll a, ll b, ll p){//a^b(mod p)
  if(b == 0) return 1;
  if(b%2 == 0){
    ll d = powmod(a,b/2,p);
    return (d*d)%p;
  }else return (a*powmod(a,b-1,p))%p;
}

main(){
  int w,h; cin >> w >> h;

  ll a=1,b=1;
  FOR(i,1,w+h-2) a = (a*i)%mod;
  FOR(i,1,w-1) b = (b*i)%mod;
  FOR(i,1,h-1) b = (b*i)%mod;
  
  cout << a*powmod(b,mod-2,mod)%mod << endl;
}
