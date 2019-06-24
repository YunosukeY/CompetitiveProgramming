#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
typedef pair<int,int> pii;

vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

int main(void){
  int n;
  while(cin>>n, n){
    map<pii,int> height, num; // そのマスの高さと上から見た数字

    rep(k,n){
      int up, front; cin >> up >> front;
      
    }

    vector<int> count(7);
    for(auto x : num){
      count[x.second]++;
    }
    cout << count[1];
    FOR(i,2,7) cout << " " << count[i];
    cout << endl;
  }
}
