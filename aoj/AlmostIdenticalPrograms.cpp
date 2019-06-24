#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

vector<string> split(string s, const string &b){
  vector<string> res;
  while(1){
    int pos = s.find(b);
    if(pos == -1) break;
    res.push_back(s.substr(0,pos));
    s = s.substr(pos+1,s.size());
  }
  if(s != "") res.push_back(s);
  return res;
}

int main(){
  string s, t;
  while(cin >> s, s != "."){
    cin >> t;
    vector<string> as = split(s,"\""), bs = split(t,"\"");
    if(as.size() != bs.size()){
      cout << "DIFFERENT" << endl;
      continue;
    }
    int even = 0, odd = 0;
    rep(i, as.size()){
      if(i % 2 == 0) even += as[i] != bs[i];
      else odd += as[i] != bs[i];
    }
    if(even != 0 or odd > 1) cout << "DIFFERENT" << endl;
    else if(odd == 1) cout << "CLOSE" << endl;
    else cout << "IDENTICAL" << endl;
  }
}
