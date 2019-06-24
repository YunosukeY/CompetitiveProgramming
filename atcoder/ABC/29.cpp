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
  int parent, left, right;
};

Node T[N];
int n;

void preorder(int u) { // 先行順
  cout << " " << u;
  if(T[u].left!=-1) preorder(T[u].left);
  if(T[u].right!=-1) preorder(T[u].right);
}
void inorder(int u) { // 中間順
  if(T[u].left!=-1) inorder(T[u].left);
  cout << " " << u;
  if(T[u].right!=-1) inorder(T[u].right);
}
void postorder(int u) { // 後行順
  if(T[u].left!=-1) postorder(T[u].left);
  if(T[u].right!=-1) postorder(T[u].right);
  cout << " " << u;
}


main(){
  int n; cin >> n;

  int num;
  rep(i,n){
    cin >> num;
    cin >> T[num].left >> T[num].right;
  }
    
  //根を探す
  int root;
  rep(i,n){
    T[i].parent=-1;
    rep(j,n){
      if(T[j].left==i) T[i].parent=j;
      else if(T[j].right==i) T[i].parent=j;
    }
    if(T[i].parent==-1){
      root=i;
      break;
    }
  }
  
  cout << "Preorder" << endl;
  preorder(root);
  cout << endl;
  cout << "Inorder" << endl;
  inorder(root);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(root);
  cout << endl;
}
