#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;

vector<int> divisor(int n){ // O(√n)約数列挙
  vector<int> res;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i * i != n) res.push_back(n/i);
    }
  }
  // sort(res.begin(),res.end());
  return res;
}

int main(){
  int in;
  while(cin >> in, in){
    in *= 2;
    vi div = divisor(in);
    //dump(div);

    int sans, lenans = -1;
    rep(i,div.size()){
      int x = div[i], y = in / div[i];
      if((x+y-1) % 2 == 1 or (x-y+1) % 2 == 1) continue;
      int s = min((x+y-1)/2, (x-y+1)/2);
      if(lenans < y and s > 0){
	lenans = y;
	sans = s;
      }
    }
    cout << sans << " " << lenans << endl;
  }
}
