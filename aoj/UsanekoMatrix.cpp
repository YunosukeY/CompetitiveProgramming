#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

#define int ll

main()
{
  int n,u,v,m; cin >> n >> u >> v >> m;
  map<int,pii> usamap,nekomap;
  rep(i,n) rep(j,n){
    int a; cin >> a;
    usamap[a] = pii(i,j);
  }
  rep(i,n) rep(j,n){
    int a; cin >> a;
    nekomap[a] = pii(i,j);
  }
  if(n > 1){
    vi usatate(n),usayoko(n),nekotate(n),nekoyoko(n);
    int usaright = 0, usaleft = 0, nekoright = 0, nekoleft = 0;
    int x = 0, y = 0;
    rep(i,m){
      int a; cin >> a;
      auto usa = usamap.find(a), neko = nekomap.find(a);
      if(usa != usamap.end()){
	usatate[usa->snd.fst]++;
	usayoko[usa->snd.snd]++;
	if(usa->snd.fst == usa->snd.snd){
	  usaleft++;
	  if(usaleft == n) x++;
	}
	if(usa->snd.fst + usa->snd.snd == n-1){
	  usaright++;
	  if(usaright == n) x++;
	}
	if(usatate[usa->snd.fst] == n) x++;
	if(usayoko[usa->snd.snd] == n) x++;
      }
      if(neko != nekomap.end()){
	nekotate[neko->snd.fst]++;
	nekoyoko[neko->snd.snd]++;
	if(neko->snd.fst == neko->snd.snd){
	  nekoleft++;
	  if(nekoleft == n) y++;
	}
	if(neko->snd.fst + neko->snd.snd == n-1){
	  nekoright++;
	  if(nekoright == n) y++;
	}
	if(nekotate[neko->snd.fst] == n) y++;
	if(nekotate[neko->snd.fst] == n) y++;
      }
      if(x >= u and y >= v) cout << "DRAW\n";
      else if(x >= u) cout << "USAGI\n";
      else if(y >= v) cout << "NEKO\n";
      if(x >= u or y >= v) return 0;
    }
  }else{
    rep(i,m){
      int a; cin >> a;
      int x = usamap.count(a), y = nekomap.count(a);
      if(x >= u and y >= v) cout << "DRAW\n";
      else if(x >= u) cout << "USAGI\n";
      else if(y >= v) cout << "NEKO\n";
      if(x >= u or y >= v) return 0;
    }
  }
  
  cout << "DRAW\n";
}
