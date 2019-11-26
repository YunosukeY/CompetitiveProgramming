#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi = vector<int>;
using vs  = vector<string>;

int main(){
  string s;
  while(cin >> s, s != "#"){
    vi a(4); rep(i,4){
      cin >> a[i];
      a[i]--;
    }
    int h = 1, w = 0;
    rep(i,s.size()) if(s[i] == '/') h++;
    rep(i,s.size()){
      if(s[i] == '/') break;
      else if(s[i] == 'b') w++;
      else w += s[i]-'0';
    }
    vs b(h);
    {
      int i = 0;
      rep(j,s.size()){
	if(s[j] == '/') i++;
	if(s[j] == 'b') b[i] += "b";
	else{
	  rep(k,s[j]-'0') b[i] += ".";
	}
      }
    }
    b[a[0]][a[1]] = '.';
    b[a[2]][a[3]] = 'b';
    string ans;
    int c = 0;
    rep(i,h){
      rep(j,w){
	if(b[i][j] == '.') c++;
	else{
	  if(c != 0){
	    ans += to_string(c);
	    c = 0;
	  }
	  ans += "b";
	}
      }
      if(c != 0){
	ans += to_string(c);
	c = 0;
      }
      if(i != h-1) ans += "/";
    }
    cout << ans << endl;
  }
}
