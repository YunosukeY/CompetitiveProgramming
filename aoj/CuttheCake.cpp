#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define pb push_back
#define w first
#define d second
typedef pair<int,int> pii;

int main(){
  while(1){
    int n,w,d; cin >> n >> w >> d;
    if(w == 0) break;
    
    vector<pii> cake = {pii(w,d)};
    rep(i,n){
      int p,s; cin >> p >> s; p--;
      pii n1, n2;
      n1 = n2 = cake[p];
      cake.erase(cake.begin() + p);
      s %= n1.w + n1.d;

      // n1 <= n2となるようにする
      if(0 < s and s < n1.w){
	if(s <=  n1.w / 2){
	  n1.w = s;
	  n2.w -= s;
	}else{
	  n2.w = s;
	  n1.w -= s;
	}
      }else{
	s -= n1.w;
	if(s <= n1.d / 2){
	  n1.d = s;
	  n2.d -= s;
	}else{
	  n2.d = s;
	  n1.d -= s;
	}
      }

      cake.pb(n1);
      cake.pb(n2);
    }

    map<int,int> mp;
    rep(i,cake.size()) mp[cake[i].w * cake[i].d]++;

    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
      if(itr == mp.begin())
	rep(i,(*itr).second)
	  if(i == 0)
	    cout << (*itr).first;
	  else
	    cout << " " << (*itr).first;
      else
	rep(i,(*itr).second)
	  cout << " " << (*itr).first;
    }
    cout << endl;
  }
}
