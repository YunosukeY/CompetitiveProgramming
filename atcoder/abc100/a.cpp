#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

int main(){
  int n; cin >> n;
  int c = 0;
  int a;
  rep(i,n){
    cin >> a;
    while(a%2==0){
      a/=2;
      c++;
    }
  }
  cout << c << endl;
}
