#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);


int main(){
  int n; cin >> n;
  map<int,int> mp;
  int a;
  rep(i,n){
    cin >> a;
    mp[a]++;
  }
  int max1 = 0,max2 = 0;
  for(auto p:mp){
    if(p.second >= 4){
      max1 = p.first;
      max2 = p.first;
    }else if(p.second >=2){
      max2 = max1;
      max1 = p.first;
    }
  }
  cout << max1 * max2 << endl;
}
