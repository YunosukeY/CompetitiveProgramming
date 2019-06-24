#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi  = vector<int>;

template <class C>
void bucketsort(vector<C>& v){
  C minv = numeric_limits<C>::max(), maxv = numeric_limits<C>::min();
  for(auto x : v){
    minv = min(minv, x);
    maxv = max(maxv, x);
  }

  vi bucket(maxv-minv+1);
  for(auto x : v) bucket[x-minv]++;

  int i = 0;
  rep(j,bucket.size()){
    rep(k,bucket[j]){
      v[i] = C(j+minv);
      i++;
    }
  }
}

template <class C>
void bucketsort(basic_string<C>& v){
  C minv = numeric_limits<C>::max(), maxv = numeric_limits<C>::min();
  for(auto x : v){
    minv = min(minv, x);
    maxv = max(maxv, x);
  }

  vi bucket(maxv-minv+1);
  for(auto x : v) bucket[x-minv]++;

  int i = 0;
  rep(j,bucket.size()){
    rep(k,bucket[j]){
      v[i] = C(j+minv);
      i++;
    }
  }
}

main(){
  vi a = {5,4,3,2,1};
  bucketsort(a);
  dump(a);

  string s = "edcba";
  bucketsort(s);
  dump(s);
}
