#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

#define int ll

const int inf = 1ll<<62;
const int mod = 1e9+7;

main(){
  int n,c,k; cin >> n >> c >> k;
  vi t(n); rep(i, n) cin >> t[i];
  sort(all(t));
  int ans = 0, time = 0, capa = 0;
  int i = 0;
  while(i < n){
    time = t[i];
    capa = 1;
    int j = i + 1;
    while(j < n){
      if(capa < c and t[j] <= time + k){
	capa++;
	j++;
      }else break;
    }
    ans++;
    i = j;
  }
  cout << ans << endl;
}
