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
  int a, b; cin >> a >> b;
  if(a <= 0 and 0 <= b) cout << "Zero\n";
  else if(a < 0){
    if(abs(a - min(-1ll, b)) % 2 == 0) cout << "Negative\n";
    else cout << "Positive\n";
  }else cout << "Positive\n";
}
