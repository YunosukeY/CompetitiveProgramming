#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define rall(a) (a).rbegin(),(a).rend()
using vi  = vector<int>;
constexpr int inf = 1ll<<30;
template<class T>bool chmax(T &a, const T &b) { if(a<b){a=b; return true;} return false;}

int main(){
  int n,m; cin >> n >> m;
  vi a(m); rep(i,m) cin >> a[i]; sort(rall(a));
  vi num = {6,2,5,5,4,5,6,3,7,6};

  vi dp(n+10,-inf);
  dp[0] = 0;
  rep(i,n) rep(j,m) chmax(dp[i + num[a[j]]], dp[i] + 1);

  for(int i = n; i > 0; ){
    rep(j,m){
      if(i-num[a[j]] >= 0 and dp[i-num[a[j]]] == dp[i]-1){
	cout << a[j];
	i -= num[a[j]];
	break;
      }
    }
  }
  cout << endl;
}
