#include<bits/stdc++.h>
using namespace std;

#include "../dump.hpp"

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

int main(){
  while(1){
    int h; cin >> h; if(h == 0) break;
    
    vector<deque<int>> stone(5, deque<int>(h));
    rep(j, h) rep(i, 5) cin >> stone[i][j]; // j = 0が天井, h-1が底
    
    int ans = 0;
    while(1){
      int tmp = ans;
      rep(j, h){ // 上から見る
	int l = 0, r = 1; // [l, r) : 同じ数字が並ぶ区間
	rep(i,4){
	  if(stone[i][j] == stone[i+1][j]){
	    r++;
	  }else{
	    if(r - l >= 3) break;
	    l = i + 1;
	    r = i + 2;
	  }
	}
	
	if(stone[l][j] != -1 and r - l >= 3){
	  FOR(i, l, r){
	    ans += stone[i][j];
	    stone[i].erase(stone[i].begin() + j); // 消して
	    stone[i].push_front(-1); // 上に詰める
	  }
	}
      }
      if(tmp == ans) break;
    }
    cout << ans << endl;
  }
}
