#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);

int main(){
  int n,a,i;
  cin >> n;
  set<int> s;
  rep(i,n){
    scanf("%d",&a);
    while(a%2==0) a=a/2;
    s.insert(a);
  }

  cout << s.size() << endl;
	
  return 0;
}
