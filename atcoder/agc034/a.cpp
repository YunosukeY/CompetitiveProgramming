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
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s; cin >> s;
  if(c < d){ // b -> a
    string t = s;
    t[b] = 'o';
    FOR(i,b+1,d+1){
      if(t[i] == '#') continue;
      if(t[i-1] == 'o') t[i] = 'o';
      if(i-2 >= b and t[i-2] == 'o') t[i] = 'o';
    }
    dump(t);
    if(t[d] != 'o'){
      cout << "No\n";
      return 0;
    }
    t = s;
    t[a] = 'o';
    FOR(i,a+1,c+1){
      if(t[i] == '#') continue;
      if(t[i-1] == 'o') t[i] = 'o';
      if(i-2 >= a and t[i-2] == 'o') t[i] = 'o';
    }
    dump(t);
    if(t[c] != 'o'){
      cout << "No\n";
      return 0;
    }else{
      cout << "Yes\n";
    }
  }else{
    string t = s;
    t[b] = 'o';
    FOR(i,b+1,d+1){
      if(t[i] == '#') continue;
      if(t[i-1] == 'o') t[i] = 'o';
      if(i-2 >= b and t[i-2] == 'o') t[i] = 'o';
    }
    if(t[d] != 'o'){
      cout << "No\n";
      return 0;
    }
    dump(s,t);
    // oのうち1箇所を#にかえて##が連続するか
    bool f = false;
    rep(i,n){
      if(t[i] != 'o') continue;
      dump(i);
      if((i > 0 and t[i-1] != '#') and (i < n-1 and t[i+1] != '#')){
	f = true;
      }
    }
    if(not f){
      cout << "No\n";
      return 0;
    }
    t = s;
    t[a] = 'o';
    FOR(i,a+1,c+1){
      if(t[i] == '#') continue;
      if(t[i-1] == 'o') t[i] = 'o';
      if(i-2 >= a and t[i-2] == 'o') t[i] = 'o';
    }
    dump(t);
    if(t[c] != 'o'){
      cout << "No\n";
      return 0;
    }else{
      cout << "Yes\n";
    }
  }
}
