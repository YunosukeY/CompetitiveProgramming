#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
 
int main(){
	int i,j;
	int n,a,b,m;
	cin >> n >> a >> b >> m;
	a--;b--;
	vi x(m),y(m),looked(n,0);
	vector< vector<int> > ad(n),dag(n);
	rep(i,n){
		ad[i].resize(n);
		dag[i].resize(n);
	}
	rep(i,m){
		cin >> x[i] >> y[i];
		ad[--x[i]][--y[i]]=1;
		ad[y[i]][x[i]]=1;
	}
	/*
	rep(i,n){
		rep(j,n)
			cout << ad[i][j] << " ";
		cout << endl;
	}
	*/
	vi d(n);
	d[a]=0;
	looked[a]=1;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		rep(i,n){
			if(ad[q.front()][i]==1 && looked[i]==0){
				looked[i]=1;
				d[i]=d[q.front()]+1;
				q.push(i);
			}
		}
		q.pop();
	}
	/*
	rep(i,n) cout << looked[i] << " ";
	cout << endl;
	rep(i,n) cout << d[i] << " ";
	cout << endl;
	*/
	rep(i,m){
		if(d[x[i]]-d[y[i]]==1)
			dag[y[i]][x[i]]=1;
		else if(d[y[i]]-d[x[i]]==1)
			dag[x[i]][y[i]]=1;
	}
	/*
	rep(i,n){
		rep(j,n)
			cout << dag[i][j] << " ";
		cout << endl;
	}
	*/
	vi sum(n),pushed(n);
	sum[a]=1;
	q.push(a);
	pushed[a]=1;
	while(!q.empty()){
		rep(i,n){
			if(dag[q.front()][i]==1){
				sum[i]+=sum[q.front()];
				//sum[i]%=1000000007;
				if(!pushed[i]){
					q.push(i);
					pushed[i]=1;
				}
			}
		}
		q.pop();
	}
	/*
	rep(i,n) cout << sum[i] << " ";
	cout << endl;
	*/
	cout << sum[b] << endl;
	return 0;
}
