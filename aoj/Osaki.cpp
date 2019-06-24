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

int convert(string ts){
  int h,m,s,t;
  h = stoi(ts.substr(0,2));
  m = stoi(ts.substr(3,2));
  s = stoi(ts.substr(6,2));
  t = h * 60 * 60 + m * 60 + s;
  return t;
}

main()
{
  while(1){
    int n; cin >> n;
    if(n == 0) break;

    vi time(24*60*60);

    rep(i,n){
      string sts,gts; cin >> sts >> gts;
      int st = convert(sts), gt = convert(gts);
      time[st]++; time[gt]--;
      //dump(time[st],time[gt]);
    }

    rep(i,sz(time)-1) time[i+1] += time[i];

    cout << *max_element(all(time)) << endl;
  }
}
