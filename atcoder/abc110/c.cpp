#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define sz(x) ((int)(x).size())

int main(){
  string s,t; cin >> s >> t;

  map<char,char> mp,mpi;
  rep(i,sz(s)){
    if(mp.count(s[i]) == 0 and mpi.count(t[i]) == 0){
      mp[s[i]] = t[i];
      mpi[t[i]] = s[i];
    }else if(mp[s[i]] == t[i] and mpi[t[i]] == s[i]) continue;
    else{
      cout << "No\n";
      return 0;
    }
  }
  
  cout << "Yes\n";
}
