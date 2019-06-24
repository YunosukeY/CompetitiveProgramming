#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
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

ll n,a,b;
vector<ll> h;

bool calc(ll m){
  ll c = 0;
  rep(i,n){
    if(h[i] - b * m > 0)
      c += (h[i] - b * m + a - b - 1) / (a - b);
    }
  if(c <= m) return true;
  else return false;
}

int main(){
  cin >> n >> a >> b;
  h.resize(n); rep(i,n) cin >> h[i];

  ll l = 0, r = 1e9 / b, m;

  while(l + 1 < r){
    m = (l + r) / 2;
    if(calc(m)) r = m;
    else l = m;
  }

  if(calc(l)) cout << l << endl;
  else cout << r << endl;
}
