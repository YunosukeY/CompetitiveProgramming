// 部分文字列のO(1)比較
// 構築O(N), 空間O(N)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int MS = 2;
const long long mod[] = {999999937LL, 1000000007LL}, base = 9973;
struct rolling_hash {
  int n;
  vector<long long> hs[MS], pw[MS];
  rolling_hash(){}
  rolling_hash(const string &s) {
    n = s.size();
    rep(i,MS){
      hs[i].assign(n+1,0);
      pw[i].assign(n+1,0);
      hs[i][0] = 0;
      pw[i][0] = 1;
      rep(j,n){
	pw[i][j+1] = pw[i][j]*base%mod[i];
	hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
      }
    }
  }

  // [l,r)
  long long hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%mod[i]+mod[i])%mod[i]; }

  bool match(int l1, int r1, int l2, int r2) {
    bool ret = 1;
    rep(i,MS) ret &= hash(l1,r1,i)==hash(l2,r2,i);
    return ret;
  }

  // 文字列とハッシュ値の比較
  bool match(int l, int r, long long h[]) {
    bool ret = 1;
    rep(i,MS) ret &= hash(l,r,i)==h[i];
    return ret;
  }
};

int main(){
  string s = "hogehoge";
  rolling_hash rh(s);
  cout << rh.match(0,4,4,8) << endl;
}
