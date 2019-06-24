#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
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
  int n,d; cin >> n >> d;
  vvi c(n);
  rep(i,n){
    int m; cin >> m;
    c[i].resize(m+1);
    rep(j,m) cin >> c[i][j+1];
    rep(j,m) c[i][j+1] += c[i][j];
    reverse(all(c[i]));
  }
  map<int,int> mp;
  rep(i,n) mp[c[i][0]]++;
  auto itr = mp.end() - 1;
  while(itr->snd != 0){
    int c = inf;
    if(itr->snd != 1){
      rep(i,n){
	if(itr->fst - c[i][1] <= d){
	  c = i;
	  break;
	}
      }
      if(c != inf){
	itr->snd--;
	mp[c[i][0]]--;
	if(mp[c[i][0]] == 0) mp.erase(c[i][0]);
	mp[c[i][1]]++;
	c[i].erase(c[i].begin() + c);
      }else{
	cout << "No\n";
	return 0;
      }
    }else{
      
      
