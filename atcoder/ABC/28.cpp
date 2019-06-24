#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define N 25

struct Node {
  int parent, left, right, height, depth;
};

Node T[N];
int n;

int setheight(int u){
  int h1 = 0,h2 = 0;
  if(T[u].left != -1)
    h1 = setheight(T[u].left) + 1;
  if(T[u].right != -1)
    h2 = setheight(T[u].right)+ 1;
  return T[u].height = max(h1, h2);
}

void setdepth(int u){
  if(T[u].parent==-1) T[u].depth=0;
  else{
    setdepth(T[u].parent);
    T[u].depth=T[T[u].parent].depth+1;
  }
}

main(){
  int n; cin >> n;

  rep(i,n){
    T[i].parent=-1;
  }

  int num;
  rep(i,n){
    cin >> num;
    cin >> T[num].left >> T[num].right;
  }

  rep(i,n) setheight(i);

  //親を探す
  rep(i,n) rep(j,n) 
    if(T[j].left==i){
      T[i].parent=j;
    }else if(T[j].right==i){
      T[i].parent=j;
    }

  int child;
  rep(i,n){
    //接点番号
    cout << i << " ";

    //親の接点番号
    cout << T[i].parent << " ";

    //兄弟の接点番号
    if(T[i].parent!=-1){
      if(T[T[i].parent].left==i)
	cout << T[T[i].parent].right;
      else if(T[T[i].parent].right==i)
	cout << T[T[i].parent].left;
    }else cout << -1;

    //子の数
    child=0;
    if(T[i].left!=-1) child++;
    if(T[i].right!=-1) child++;
    cout << " " << child << " ";

    //深さ
    setdepth(i);
    cout << T[i].depth << " ";

    //高さ
    cout << T[i].height << endl;
  }
}
