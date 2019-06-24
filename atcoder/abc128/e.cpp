#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)

signed main(){
  int n, q; cin >> n >> q;
  vector<tuple<int,int,int>> event;
#define event(i,j) get<j>(event[i])
  set<int> xs;
  priority_queue<int,vector<int>,greater<int>> p;

  rep(i,n){
    int s, t, x; cin >> s >> t >> x;
    event.emplace_back(s-x,1,x);
    event.emplace_back(t-x,-1,x);
  }
  sort(event.begin(),event.end());
  rep(i,q){
    int d; cin >> d;
    p.push(d);
  }

  rep(i,event.size()){
    while(1){
      if(p.empty()) break;
      if(event(i,0) <= p.top()) break;
      if(xs.empty()) cout << -1 << endl;
      else{
	cout << *xs.begin() << endl;
	xs.erase(xs.begin());
      }
      p.pop();
    }

    if(event(i,1) == 1)
      xs.insert(event(i,2));
    else
      xs.erase(event(i,2));
  }
  while(!p.empty()){
    cout << -1 << endl;
    p.pop();
  }
}
