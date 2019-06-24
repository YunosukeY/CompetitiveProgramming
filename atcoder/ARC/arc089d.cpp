#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
#define sz(x) ((int)(x).size())

typedef vector<int> vi;
typedef vector<vi> vvi;

void show(vvi b){
  rep(i, sz(b)){
    rep(j, sz(b[i])){
      if(b[i][j] >= 0) cout << " ";
      cout << b[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  int n,k; cin >> n >> k;
  int size = 6 * k; // 必要なのは真ん中の2k * 2k
  vvi b(size, vi(size));
  rep(i,n){
    int x, y; char c;
    cin >> x >> y >> c;
    if(c == 'W') y += k;
    x %= 2 * k;
    y %= 2 * k;
    // 条件を満たす"右下"マスの集合の市松模様を考える
    rep(j,2){
      rep(z, 2) rep(w, 2){
	  b[x + 2 * z * k][y + 2 * w * k]++;
	  b[x + 2 * z * k][y + k + 2 * w * k]--;
	  b[x + k + 2 * z * k][y + 2 * w * k]--;
	  b[x + k +  2 * z * k][y + k + 2 * w * k]++;
      }
      x += k; y += k;
    }
    //show(b);
  }
  //show(b);

  // 累積和
  rep(i, size) rep(j, size - 1) b[i][j + 1] += b[i][j];
  rep(i, size - 1) rep(j, size) b[i + 1][j] += b[i][j];
  //show(b);

  int ans = 0;
  FOR(i,2*k,4*k) FOR(j,2*k,4*k) ans = max(ans, b[i][j]);
  cout << ans << endl;
}
