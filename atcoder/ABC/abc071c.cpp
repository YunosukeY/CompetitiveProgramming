#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define fst first
#define snd second
typedef long long ll;

main(){
  int n; cin >> n;
  ll a;
  map<ll, ll> mp;
  rep(i, n){
    cin >> a;
    mp[a]++;
  }

  ll ss = 0, ls = 0;

  for(auto x : mp){
    if(x.snd >= 4){
      ss = x.fst;
      ls = x.fst;
    }else if(x.snd >= 2){
      ss = ls;
      ls = x.fst;
    }
  }

  cout << ss * ls << endl;
}
