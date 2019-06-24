#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

string s;
vector<int> eval(3);
map<char,function<int(int,int)>> op;

int solve(int &i){
  if(isdigit(s[i])){
    return s[i++] - '0';
    
  }else if('P' <= s[i] and s[i] <= 'R'){
    return eval[s[i++] - 'P'];
    
  }else if(s[i] == '-'){
    i++; // '-'
    return  2 - solve(i);

  }else if(s[i] == '('){
    i++; // '('
    int l = solve(i);
    
    // '+' or '*'
    char m = s[i];
    assert(op.count(m));
    i++;

    int r = solve(i);
    i++; // ')'
    
    return op[m](l,r);
  }
  assert(false);
}

int rec(int depth){
  if(depth == 3){
    int index = 0;
    return solve(index) == 2;
  }
  int res = 0;
  rep(i,3){
    eval[depth] = i;
    res += rec(depth+1);
  }
  return res;
}

int main(void){
  op['+'] = [](int x,int y){
    if(x == 2 or y == 2) return 2;
    else if(x == 1 or y == 1) return 1;
    else return 0;
  };
  op['*'] = [](int x,int y){
    if(x == 0 or y == 0) return 0;
    else if(x == 1 or y == 1) return 1;
    else return 2;
  };
  
  while(cin >> s, s != "."){
    int res = rec(0);
    cout << res << endl;
  }
}
