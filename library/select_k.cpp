#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
using ll  = long long;
using vi  = vector<int>;

template<class C>
int partition(vector<C> &v, int beg, int en){
  C pivot = v[en-1];
  int i = beg;
  FOR(j,beg,en-1){
    if(v[j] <= pivot){
      swap(v[i], v[j]);
      i++;
    }
  }
  swap(v[i], v[en-1]);
  return i;
}

// aでk番目に小さい値を返す
template<class C>
C select(vector<C> &v, int beg, int en, int k){
  int q = partition(v, beg, en);
  if(q == k) return v[q];
  else if(q < k) return select(v,q+1,en,k);
  else return select(v,0,q,k);
}

int main(){
  int n;
  while(cin >> n, n){
    vi a(n);
    rep(i,n){
      cin >> a[i];
    }
    cout << select(a, 0, n, n/2) << endl;
  }
}
