#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())

int main(){
  int n; cin >> n;
  map<int,int> mp;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  a.erase(unique(a.begin(), a.end()), a.end());
  sort(a.begin(), a.end());
  //for(int i = 0; i < sz(a); i++) cout << a[i] << endl;
  
  bool ans = false;
  if(sz(mp) == 1){
    if(a[0] + 1 == n or a[0] * 2 <= n)
      ans = true;
  }else if(sz(mp) == 2)
    if(a[0] + 1 == a[1]) // a[1]種類
      if((a[1] - a[0] > 0) and ((a[1] - a[0]) * 2 <= mp[a[1]])) // a[0]は一匹グループ、mp[a[1]]匹はa[1] - a[0]グループで各2匹以上
	ans = true;

  if(ans) cout << "Yes\n";
  else cout << "No\n";
}
