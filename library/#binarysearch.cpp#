#include<bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;i++)
typedef long long ll;
constexpr ll inf = 1ll<<61;

bool solve(int mid){
  bool res = true;
  return res;
}

int bs(int _ok, int _ng){
  int ok = _ok;
  int ng = _ng;

  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;
    if(solve(mid)){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  return ok;
}

// (value以下の最大の要素, value以上の最小の要素)
// 入力はsort,unique済みで番兵が最初と最後にいるものとする
template<class ForwardIterator, class T>
pair<ForwardIterator, ForwardIterator>
f(ForwardIterator first, ForwardIterator last, const T& value){
  ForwardIterator lb = lower_bound(first, last, value);
  if(*lb == value) return make_pair(lb,lb);
  else return make_pair(lb-1,lb);
}

// (valueより小さい最大の要素, valueより大きい最小の要素)
// 入力はsort,unique済みで番兵が最初と最後にいるものとする
template<class ForwardIterator, class T>
pair<ForwardIterator, ForwardIterator>
g(ForwardIterator first, ForwardIterator last, const T& value){
  ForwardIterator ub = upper_bound(first, last, value);
  ForwardIterator mv = ub - 1;
  if(*mv < value) return make_pair(mv,ub);
  else return make_pair(mv-1,ub);
}

signed main(){
  int n; cin >> n;
  vector<int> a(n+2); rep(i,n) cin >> a[i];
  a[n] = inf; a[n+1] = -inf;
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());

  auto p = f(a.begin(), a.end(), 4);
  cout << *p.first << " " << *p.second << endl;

  p = f(a.begin(), a.end(), 5);
  cout << *p.first << " " << *p.second << endl;

  p = g(a.begin(), a.end(), 4);
  cout << *p.first << " " << *p.second << endl;

  p = g(a.begin(), a.end(), 5);
  cout << *p.first << " " << *p.second << endl;

}
