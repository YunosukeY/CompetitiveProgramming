#include<bits/stdc++.h>

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#define assert(...)
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(){
#define int ll
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  sort(all(a));
  int x = a[n-1] / 2, y;

  if(n % 2 == 0)
    y = x;
  else
    y = x + 1;

  int l = *(upper_bound(all(a),x) - 1);
  int r = *lower_bound(all(a), y);
  if(r == a[n-1]){
    r = l;
    y = x;
  }
  dump(x,l,y,r);
  cout << a[n-1] << " ";
  if(abs(l - x) < abs(r - y)) cout << l;
  else cout << r;
  cout << endl;
}
