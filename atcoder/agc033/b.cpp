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

signed main(){
  int h, w, n; cin >> h >> w >> n;
  int sr, sc; cin >> sr >> sc;
  string s,t ; cin >> s >> t;

  int lb = 1, ub = h;
  ROF(i,n,0){
    if(t[i] == 'D'){
      lb = max(1ll,lb-1);
    }else if(t[i] == 'U'){
      ub = min(h,ub+1);
    }

    if(s[i] == 'D'){
      ub--;
      if(ub == 0 or ub < lb){
	cout << "NO" << endl;
	return 0;
      }
    }else if(s[i] == 'U'){
      lb++;
      if(h < lb or ub < lb){
	cout << "NO" << endl;
	return 0;
      }
    }
  }
  if(lb <= sr and sr <= ub){
  }else{
    cout << "NO" << endl;
    return 0;
  }

  lb = 1;
  ub = w;
  ROF(i,n,0){
    if(t[i] == 'R'){
      lb = max(1ll,lb-1);
    }else if(t[i] == 'L'){
      ub = min(w,ub+1);
    }
    dump(lb,ub);

    if(s[i] == 'R'){
      ub--;
      if(ub == 0 or ub < lb){
	cout << "NO" << endl;
	return 0;
      }
    }else if(s[i] == 'L'){
      lb++;
      if(w < lb or ub < lb){
	cout << "NO" << endl;
	return 0;
      }
    }
    dump(lb,ub);
  }
  if(lb <= sc and sc <= ub){
  }else{
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
}
