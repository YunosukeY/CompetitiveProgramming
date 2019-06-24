#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

int main(){
  int n, k; cin >> n >> k;
  int a; rep(i,n) cin >> a;
  cout << (n + k - 3) / (k - 1) << endl;
}
