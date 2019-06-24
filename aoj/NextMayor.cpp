#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
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
  while(1){
    int n,p; cin >> n >> p;
    if(n == 0) break;
    vi m(n);
    int pos = 0;
    int tmp = p;
    while(1){
      if(tmp > 1){
	tmp--;
	m[pos]++;
      }else if(tmp == 1){
	tmp--;
	m[pos]++;
	if(m[pos] == p){
	  cout << pos << endl;
	  break;
	}
      }else{
	tmp = m[pos];
	m[pos] = 0;
      }
      pos++;
      pos %= n;
    }	
  }
}
