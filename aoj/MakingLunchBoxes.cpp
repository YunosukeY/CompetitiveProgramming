#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}

string x(const string &a, const string &b){
  string ans(a.size(),'0');
  rep(i,a.size()){
    if(a[i] == b[i]) ans[i] = '0';
    else ans[i] = '1';
  }
  return ans;
}

signed main(){
  int n, m;
  while(cin >> n >> m, n){
    vector<string> b(n);
    rep(i,n) cin >> b[i];

    map<string,int> dp; // dp[i]:集合iのときの個数
    string zero(m,'0');
    dp[zero] = 0;
    rep(i,n){
      map<string,int> next = dp;
      for(auto &p : dp)
	chmax(next[x(p.first,b[i])],p.second+1);
      dp = move(next);
    }
    cout << dp[zero] << endl;
  }
}
