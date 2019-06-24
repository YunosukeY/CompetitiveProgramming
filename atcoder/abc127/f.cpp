#include <bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using ll  = long long;

signed main(){
  int q; cin >> q;

  priority_queue<int> pq1; // 中央値以下を管理
  priority_queue<int,vector<int>,greater<int>> pq2; // 中央値より大きいものを管理
  int minv = 0;
  {
    int a, b; cin >> a >> a >> b;
    pq1.push(a);
    minv += b;
  }
  rep(_,q-1){
    assert(pq1.size() == pq2.size() or pq1.size() == pq2.size() + 1);
    int t; cin >> t;
    if(t == 1){
      int a, b; cin >> a >> b;

      if(pq1.top() < a){
	if(pq2.size()) minv += a - pq2.top();
	else minv += a - pq1.top();
	pq2.push(a);
      }else{
	minv += pq1.top() - a;
	pq1.push(a);
      }
      
      if(pq1.size() < pq2.size()){
	pq1.push(pq2.top());
	pq2.pop();
      }else if(pq1.size() > pq2.size() + 1){
	pq2.push(pq1.top());
	pq1.pop();
      }

      minv += b;
    }else{
      cout << pq1.top() << " " << minv << endl;
    }
  }
}
