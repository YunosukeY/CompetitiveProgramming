#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(),(a).end()

using State = string::const_iterator;
State en;

string String(State &begin);
char Letter(State &begin);
char Alpha(State &begin);

string Cipher(State &begin){
  string ret;
  while(begin != en and *begin != ']'){
    ret += String(begin);
  }
  return ret;
}

string String(State &begin){
  string ret;
  if(*begin == '['){
    ++begin;
    ret = Cipher(begin);
    reverse(all(ret));
    ++begin;
  }else{
    ret = {Letter(begin)};
  }
  return ret;
}

char Letter(State &begin){
  int pm = 0;
  int ret;
  while(1){
    if(*begin == '+'){
      pm++;
      ++begin;
    }else if(*begin == '-'){
      pm--;
      ++begin;
    }else{
      ret = Alpha(begin);
      break;
    }
  }
  if(ret == '?') return 'A';
  ret += pm;
  while('Z' < ret) ret -= 26;
  while(ret < 'A') ret += 26;
  return ret;
}

char Alpha(State &begin){
  char ret = *begin;
  ++begin;
  return ret;
}

signed main(){
  string s;
  while(cin >> s, s != "."){
    en = s.end();
    State beg = s.begin();
    cout << Cipher(beg) << endl;
  }
}
