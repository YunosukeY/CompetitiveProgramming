#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define pb push_back
using vi  = vector<int>;

vi mp; // a : mp[0], b : mp[1], c : mp[2], d : mp[3]
vector<function<int(int,int)>> ops;

typedef string::const_iterator State;
int letter(State &begin){
  int res = mp[*begin - 'a'];
  ++begin;
  return res;
}
int hashf(State &begin){
  if(*begin == '['){
    ++begin; // '['
    
    int optype;
    if(*begin == '+') optype = 0;
    else if(*begin == '*') optype = 1;
    else if(*begin == '^') optype = 2;
    else assert(false);
    ++begin; // operator
    
    int lop = hashf(begin), rop = hashf(begin);

    ++begin; // ']' 
    
    return ops[optype](lop,rop);
  }else{
    return letter(begin);
  }
}

signed main(){
  string s;
  mp.resize(4);
  ops.push_back([](int a, int b){ return a|b; });
  ops.push_back([](int a, int b){ return a&b; });
  ops.push_back([](int a, int b){ return a^b; });
  while(cin >> s, s != "."){
    string p; cin >> p;
    rep(i,4) mp[i] = p[i] - '0';
    State begin = s.begin();
    int ans = hashf(begin);
    int cnt = 0;
    rep(a,10) rep(b,10) rep(c,10) rep(d,10){
      mp[0] = a; mp[1] = b; mp[2] = c; mp[3] = d;
      begin = s.begin();
      if(ans == hashf(begin)) cnt++;
    }
    cout << ans << " " << cnt << endl;
  }
}
