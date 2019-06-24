#include<bits/stdc++.h>

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(){
#define int ll
  int n,x; cin >> n >> x;
  vi a(n); rep(i,n) cin >> a[i];
  int ans = 0;
  if(a[0] > x){
    ans += a[0] - x;
    a[0] = x;
  }
  rep(i,n-1)
    if(a[i] + a[i+1] > x){
      ans += a[i] + a[i+1] - x;
      a[i+1] = x - a[i];
    }
  cout << ans << endl;
}
