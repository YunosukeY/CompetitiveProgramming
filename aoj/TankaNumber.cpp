#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
using ll  = long long;

int mypow(int a, ll n){
  int ans = 1;
  while(n){
    if(n&1) ans *= a;
    a *= a;
    n = n >> 1;
  }
  return ans;
}

signed main(){
  int n;
  while(cin >> n, n){
    string ans;
    int cur = 0; // k-1桁までの数
    int k = 2; // 桁数
    int a, b = -1;
    
    // 桁数kを決定してから最上位の桁aを決定する
    while(1){
      int tmp = 81*(mypow(2,k-1)-1); // k桁の場合の数
      if(cur + tmp < n){
	cur += tmp;
	k++;
	continue; // k桁ではないのでk+1桁か調べる
      }
      
      tmp /= 9; // 最上位がiだった時の場合の数
      FOR(i,1,10){
	if(cur < n and n <= cur + tmp){
	  a = i;
	  break;
	}else{
	  cur += tmp;
	}
      }
      break;
    }
    ans += to_string(a);

    // k-1桁目を決める
    while(k-1 > 0){
      if(b == -1){ // もう1つの数が未定
	int tmpa = mypow(2,k-2); // この桁がaでないとき
	int tmpb = 9 * mypow(2,k-2) - 9; // この桁がaのとき
	FOR(i,0,10){
	  int tmp; // k-1桁目がiのときの場合の数
	  if(a == i) tmp = tmpb;
	  else tmp = tmpa;
	  if(cur < n and n <= cur + tmp){
	    if(a != i)
	      b = i;
	    break;
	  }else
	    cur += tmp;
	}
	if(b == -1) ans += to_string(a);
	else{
	  ans += to_string(b);
	  if(a > b) swap(a,b);
	}
      }else{
	// 二進数みたいな感じ
	if(n <= cur + mypow(2,k-2)) ans += to_string(a);
	else{
	  cur += mypow(2,k-2);
	  ans += to_string(b);
	}
      }
      k--;
    }
    cout << ans << endl;
  } 
}
