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

main()
{
  int n; cin >> n;
  vi p(n); rep(i,n) cin >> p[i];
  
  vi a(n),b(n);
  rep(i,n){
    int pos;
    rep(j,n) if(p[j] == i + 1) pos = j;
    a[i] = 3000 * i + pos + 1;
    b[i] = 3000 * (n - i);
  }

  //rep(i,n) cout << a[p[i]-1]+b[p[i]-1] << endl;

  rep(i,n-1) cout << a[i] << " ";
  cout << a[n-1] << endl;
  rep(i,n-1) cout << b[i] << " ";
  cout << b[n-1] << endl;
}
