#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

int solve(vector<string> const &vs, int &i, int j){
  //cout << vs[i][j] << endl; // 0..9, +, or *
  
  if(isdigit(vs[i][j])){
    int res = vs[i][j] - '0';
    //cout << res << endl;
    return res;
  }
  
  char op = vs[i][j]; // + or *
  vector<int> term;
  i++; j++;
  while(i < vs.size() and vs[i].size() == j+1){
    term.push_back(solve(vs, i, j));
    i++;
  }
  i--;
  int res;
  if(op == '+') res = accumulate(all(term),0);
  else res = accumulate(all(term),1,multiplies<int>());
  
  //cout << res << endl;
  return res;
}

int main(void){
  while(1){
    int n;
    cin >> n;
    if(!n) break;

    vector<string> vs(n);
    rep(i, n)
      cin >> vs[i];

    int index = 0, depth = 0; // vs[index]の.の数 = depth
    cout << solve(vs, index, depth) << endl;
  }
}
