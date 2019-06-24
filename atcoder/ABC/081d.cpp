#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const double PI=acos(-1.0);
#define inf 10000000

int main(){
	int i,j,k;
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int min=inf,max=-1*inf;
	rep(i,n){
		if(min>a[i]){
			min=a[i];
			j=i;
		}
		if(max<a[i]){
			max=a[i];
			k=i;
		}
	}
	if(min==max){
	  cout << 0 << endl;
	  return 0;
	}
	cout << 2*n-1 << endl;
	j++;
	k++;
	if(abs(max)>=abs(min)){
		rep(i,n) cout << k << " " << i+1 << endl;
		For(i,1,n) cout << i << " " << i+1 << endl;
	}else{
		rep(i,n) cout << j << " " << i+1 << endl;
		for(i=n;i>1;i--){
			cout << i << " " << i-1 << endl;
		}
	}

	return 0;
}
