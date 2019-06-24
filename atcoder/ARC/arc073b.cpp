#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a,k) accumulate(a.begin(),a.begin()+k,0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  ll n,w; cin >> n >> w;
  vector<vector<ll>> v(4);
  rep(i,4) v[i].pb(0);
  ll a,b; cin >> a >> b; v[0].pb(b);
  rep(i,n-1){
    ll c,d; cin >> c >> d;
    v[c - a].pb(d);
  }
  
  rep(i,4) sort(rall(v[i]));

  ll ans = 0;

  rep(i,v[0].size()) rep(j,v[1].size()) rep(k,v[2].size()) rep(l,v[3].size()){
    ll totalw = a * i + (a+1) * j + (a+2) * k + (a+3) * l;
    if(totalw > w) break; // lを増やしてもしょうがないのでbreak;
    ll totalv = SUM(v[0],i) + SUM(v[1],j) + SUM(v[2],k) + SUM(v[3],l);
    ans = max(ans, totalv);
  }

  cout << ans << endl;
}
