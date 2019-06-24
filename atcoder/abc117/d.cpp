#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define sz(x) ((int)(x).size())
using ll  = long long;
using vi  = vector<int>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
int maxd = 40; // 最大桁数
#define bit(n) (1ll << n)

vi a;
int f(int x){
  int res = 0;
  rep(i,sz(a)) res += x ^ a[i];
  return res;
}  

signed main(){
  int n,k; cin >> n >> k; k++;
  a.resize(n); rep(i,n) cin >> a[i];

  // 最上位の1ビットが下から何桁目か(ただしk==0 <=> x==0)
  int x = 0;
  ROF(i,maxd,0)
    if((k >> i) & 1){
      x = i+1;
      break;
    }

  // 各ビットを何にしたほうが良いか
  int y = a[0];
  FOR(i,1,n) y ^= a[i];

  int res = f(0);
  rep(i,x){ // どこを折ってそれ以下を貪欲に取るか全探索
    if(((k >> i) & 1) == 0) continue; // 折れない
    int tmp = k;

    tmp &= ~bit(i);
    cout << tmp << endl;
    int mask = ~(bit(i) - 1);
    cout << mask << endl;
    tmp &= mask;
    cout << tmp << endl;
    tmp |= y & mask;
    cout << (y & mask) << endl;
    cout << tmp << endl;
    chmax(res, f(tmp));
  }
  cout << res << endl;
}
