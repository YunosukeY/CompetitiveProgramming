#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define sz(x) ((int)(x).size())
using ll  = long long;
using vi  = vector<int>;

int countBlock(vi x){
  int res = 0;
  FOR(i,1,sz(x))
    if(x[i-1] <= 0 and x[i] > 0) res++;
  return res;
}

bool hasPositive(vi x){
  rep(i,sz(x)) if(x[i] > 0) return true;
  return false;
}

int main(){
  int n; cin >> n;
  vi h(n+1); rep(i,n) cin >> h[i+1];

  int res = 0;
  while(hasPositive(h)){
    res += countBlock(h);
    rep(i,sz(h)) h[i]--;
  }
  cout << res << endl;
}
