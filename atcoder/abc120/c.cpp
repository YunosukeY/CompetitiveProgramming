#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

int main(){
  string s; cin >> s;
  vector<int> a(2);
  rep(i,s.size()) a[s[i]-'0']++;
  cout << 2*min(a[0],a[1]) << endl;
}
