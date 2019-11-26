#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
const int inf = 1<<30;
using vs  = vector<string>;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

int n, m;
vs info;
map<string, int> memo;

int rec(string s){
  int c = 0;
  rep(i,m) if(s[i] == '1') c++;
  if(c <= 1) return 0;

  if(memo.count(s)) return memo[s];

  int res = inf;
  rep(i,n){ // i番目の質問をするとき
    string zero = s, one = s;
    rep(j,m){ // j番目のもの
      if(s[j] == '0') continue; // もう区別されている
      if(info[j][i] == '0') one[j] = 0;
      else zero[j] = 0;
    }
    if(zero == s or one == s) continue;
    int tmp = max(rec(zero), rec(one));
    chmin(res, tmp);
  }
  memo[s] = res+1;
  return res+1;
}

int main(){
  while(cin >> n >> m, n){
    info.resize(m);
    rep(i,m) cin >> info[i];

    memo.clear();
    string all;
    rep(i,m) all += '1';
    cout << rec(all) << endl;
  }
}
