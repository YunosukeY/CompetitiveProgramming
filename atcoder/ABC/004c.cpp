#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;  

int main(){
  int n;
  int i;
  cin >> n;
  n%=30;
  vi card(6);
  rep(i,6) card[i]=i+1;
  rep(i,n) swap(card[i%5],card[i%5+1]);
  rep(i,6) cout << card[i];
  cout << endl;
  return 0;
}
