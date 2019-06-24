#include<bits/stdc++.h>

#include"../../dump.hpp"

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

#define mod 1000000007

main(){
  int n; cin >> n;
  vi a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(all(a));
  sort(all(c));
  dump(a,c);

  ll ans = 0;
  rep(i,n){
    auto itra = upper_bound(all(a),b[i]-1);
    auto itrc = lower_bound(all(c),b[i]+1);
    //dump(*itra, *itrc);
    ans += (itra - a.begin()) * (c.end() - itrc);
  }

  cout << ans << endl;
}
