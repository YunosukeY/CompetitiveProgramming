#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;

int x,y;
const int dif[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool issafe(int a,int b){
  if(0<=a && a<x && 0<=b && b<y)
    return true;
  else return false;
}
  

int main(){
  int i,j;
  vector< vector<char> > a;
  pair<int,int> p,p2;
  queue< pair<int,int> > q;
  int count;
  while(1){
    cin >> x >> y;
    if(x==0 && y==0) break;
    a.resize(x);
    rep(i,x)
      a[i].resize(y);
    rep(j,y){
      rep(i,x){
	cin >> a[i][j];
	if(a[i][j]=='@'){
	  p.first=i;
	  p.second=j;
	  a[i][j]='#';
	}
      }
    }
    /*
    rep(j,y){
      rep(i,x)
	cout << a[i][j];
      cout << endl;
    }
    */
    count=1;
    q.push(p);
    while(!q.empty()){
      p=q.front();
      //cout << p.first << " " << p.second << endl;
      rep(i,4){
	p2.first=p.first+dif[i][0];
	p2.second=p.second+dif[i][1];
	//cout << p2.first << " " << p2.second << endl;
	if(issafe(p2.first,p2.second) && a[p2.first][p2.second]=='.'){
	    count++;
	    a[p2.first][p2.second]='#';
	    q.push(p2);
	}
      }
      q.pop();
    }
    cout << count << endl;
    /*
    rep(j,y){
      rep(i,x)
	cout << a[i][j];
      cout << endl;
    }
    */
  }
  
  return 0;
}
