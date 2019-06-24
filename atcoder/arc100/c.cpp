#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
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

#define maxLoop 1000

vi a;
int n;

ll f(ll x){
  ll res = 0;
  rep(i,n) res += abs(a[i] - (x + i + 1));
  return -res;
}

ll search(ll left, ll right)
{
	for (int loop = 0; loop < maxLoop; ++loop){
		if (f((left * 2 + right) / 3) > f((left + right * 2) / 3)){
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	return (right + left) * 0.5;
}

int main(){
#define int ll
  cin >> n;
  a.resize(n); rep(i,n) cin >> a[i];
  cout << -f(search(-1e9,1e9)) << endl;
}
