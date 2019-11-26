#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi = vector<int>;
using Tree = vector<map<int,int>>;
#define LEFT 0
#define RIGHT 1

typedef string::const_iterator State;

int number(State &begin){
  int res = 0;
  while(isdigit(*begin)){
    res *= 10;
    res += *begin - '0';
    ++begin;
  }
  return res;
}

int parse(State &begin, Tree &t, vi &mp){
  if(*begin == ')') return -1;

  ++begin; // '('
  int l = parse(begin, t, mp); // ノード番号
  ++begin; // ')'
  ++begin; // '[';
  int p = number(begin); // ノードの数
  ++begin; // ']';
  ++begin; // '(';
  int r = parse(begin, t, mp); // ノード番号
  ++begin; // ')';

  mp.push_back(p);
  t.resize(t.size()+1);
  if(l != -1) t.back()[LEFT] = l;
  if(r != -1) t.back()[RIGHT] = r;

  return t.size()-1;
}

string syncDFS(int ap, Tree at, vi amp, int bp, Tree bt, vi bmp){
  string res;

  res += "(";
  if(at[ap].count(LEFT) and bt[bp].count(LEFT))
    res += syncDFS(at[ap][LEFT], at, amp, bt[bp][LEFT], bt, bmp);
  res += ")[";
  res += to_string(amp[ap] + bmp[bp]);
  res += "](";
  if(at[ap].count(RIGHT) and bt[bp].count(RIGHT))
    res += syncDFS(at[ap][RIGHT], at, amp, bt[bp][RIGHT], bt, bmp);
  res += ")";

  return res;
}

int main(){
  string a, b;
  cin >> a >> b;

  Tree at, bt;
  vi amp, bmp;
  State begin = a.begin();
  int aroot = parse(begin, at, amp);
  begin = b.begin();
  int broot = parse(begin, bt, bmp);

  cout << syncDFS(aroot, at, amp, broot, bt, bmp) << endl;
}
