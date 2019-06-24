#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
#define fill(a,x) memset(a,x,sizeof(a))
#define zero(a) fill(a,0)
#define minus(a) fill(a,-1)
#define dbg(x) cout << #x"=" << x << endl

const int INF = INT_MAX/3;
const int LIMIT = 500000;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n;
int a[LIMIT];
int temp[LIMIT];
int ans;

void merge(int a[], int left, int middle, int right){
  int n1 = middle - left;
  int n2 = right - middle;
  int l[n1];
  int r[n2];
  rep(i, n1) l[i] = a[left + i];
  rep(i, n2) r[i] = a[middle + i];
  l[n1] = INF;
  r[n2] = INF;
  int i = 0;
  int j = 0;
  int k;
  FOR(k, left, right){
    if(l[i] < r[j]) a[k] = l[i++];
    else{
      a[k] = r[j++];
      if(i!=n1)
	ans+=n1-i;
    }
  }
  //cout << ans << endl;
}

void mergeSort(int a[], int left, int right){
  if(left + 1 < right){
    int middle = (left + right) / 2;
    mergeSort(a, left, middle);
    mergeSort(a, middle, right);
    merge(a, left, middle, right);
    /*
    rep(i, n){
      cout << a[i];
      if(i != n - 1) cout << ' ';
    }
    cout << endl;
    */
    cout << ans << endl;
    //ans++;
  }
}

int main(){
  ans=0;
  cin >> n;
  rep(i, n) cin >> a[i];
  mergeSort(a, 0, n);
  /*  
  rep(i, n){
    cout << a[i];
    if(i != n - 1) cout << ' ';
  }
  cout << endl;
  cout << ans << endl;
  */
  return 0;
}
