#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()

class TwoMap{
public:
  map<int,int> l, r;
  int lsz, rsz;

  TwoMap(){lsz = rsz = 0;}
  TwoMap(int a){
    l[a]++;
    lsz = 1;
    rsz = 0;
  }
  TwoMap(vector<int> a){
    int n = a.size();
    sort(all(a));
    rep(i,(n+1)/2) l[a[i]]++;
    FOR(i,(n+1)/2,n) r[a[i]]++;
    lsz = (n+1)/2;
    rsz = n - lsz;
  }

  void insert(int a){
    if(lsz == 0){
      l[a]++;
      lsz++;
      return;
    }
    auto litr = l.end();
    litr--;
    if(litr->first < a){
      r[a]++;
      rsz++;
    }else{
      l[a]++;
      lsz++;
    }
    if(lsz < rsz){
      auto ritr = r.begin();
      ritr->second--;
      rsz--;
      l[ritr->first]++;
      lsz++;
      if(ritr->second == 0) r.erase(ritr);
    }else if(lsz > rsz + 1){
      litr->second--;
      lsz--;
      r[litr->first]++;
      rsz++;
      if(litr->second == 0) l.erase(litr);
    }
  }

  int minv(){
    return l.begin()->first;
  }

  int medv(){
    auto litr = l.end();
    litr--;
    return litr->first;
  }
  
  int maxv(){
    if(rsz == 0) return medv();
    auto ritr = r.end();
    ritr--;
    return ritr->first;
  }
};

ostream& operator<<(ostream &os, const TwoMap &tm){
  os << tm.l << ", " << tm.r;
  return os;
}

signed main(){
  int n = 10;
  vector<int> input(n);
  iota(all(input),0);
  random_device gen;
  mt19937 mt(gen());
  shuffle(all(input),mt);
  dump(input);

  TwoMap tm;
  rep(i,n){
    tm.insert(input[i]);
    dump(tm.minv(),tm.medv(),tm.maxv());
  }
}
