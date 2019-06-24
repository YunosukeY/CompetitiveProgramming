#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../dump.hpp"
#else
#define dump(...)
#endif

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(int i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define sz(x) ((int)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int,int>;
constexpr ll inf = 1ll<<61;
constexpr ll mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>void add(T &a, const T &b){a += b; a %= mod;}
template<typename FI>
void parted_rotate(FI first1, FI last1, FI first2, FI last2) {
  if(first1 == last1 || first2 == last2) return;
  FI next = first2;
  while(first1 != next) {
    std::iter_swap(first1++, next++);
    if(first1 == last1) first1 = first2;
    if(next == last2) next = first2;
    else if(first1 == first2) first2 = next;
  }
}

template<typename BI>
bool next_combination_imp(BI first1, BI last1, BI first2, BI last2) {
  if(first1 == last1 || first2 == last2) return false;
  BI target = last1; --target;
  BI last_elem = last2; --last_elem;
  while(target != first1 && !(*target < *last_elem)) --target;
  if(target == first1 && !(*target < *last_elem)) {
    parted_rotate(first1, last1, first2, last2);
    return false;
  }
  BI next = first2;
  while(!(*target < *next)) ++next;
  std::iter_swap(target++, next++);
  parted_rotate(target, last1, next, last2);
  return true;
}

template<typename BI>
inline bool next_combination(BI first, BI mid, BI last) {
  return next_combination_imp(first, mid, mid, last);
}

signed main(){
  int n, k; cin >> n >> k;
  vi a(n); rep(i,n) cin >> a[i];
  sort(all(a));
  int ans = inf;
  do{
    int tmp = 0;
    int sum = 0;
    rep(i,k) sum += a[i];
    for(int i = 1000000000; i > 0; i/=10){
      if(sum >= 5*i){
	sum -= 5*i;
	tmp++;
      }
      if(sum >= i){
	tmp += sum / i;
	sum %= i;
      }
    }
    ans = min(ans, tmp);
  }while(next_combination(a.begin(),a.begin()+k,a.end()));
  cout << ans << endl;
}
