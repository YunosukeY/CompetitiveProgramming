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
  int n,x; cin >> n >> x;

  if(n == 2)
    if(x == 2) cout << "Yes\n1\n2\n3\n";
    else cout << "No\n";
  else if(x == 1 or x == 2 * n - 1) cout << "No\n";
  else{
    cout << "Yes\n";
    if(x == 2){
      rep(i,n/2 - 1) cout << 5+i << endl;
      cout << "3\n2\n1\n4\n";
      rep(i,n/2) cout << n-i << endl;
    }else{
      vi a;
      rep(i,2*n-1) if(i+1 <= x-3 or x+2 <= i+1) a.pb(i+1);
      rep(i,n/2 - 1) cout << a[i] << endl;
      cout << x-2 << endl << x << endl << x+1 << endl << x-1 << endl;
      FOR(i,n/2-1,sz(a)) cout << a[i] << endl;
    }
  }
}
