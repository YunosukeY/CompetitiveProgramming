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
const int LIMIT = 10000;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n;
string s;
int ans;

int findMax(int a[], int left, int right){
    int mid = (left + right) / 2;
    if(left == right - 1) return a[left];
    else{
        int former = findMax(a, left, mid);
        cout << former << endl;
        int later = findMax(a, mid, right);
        cout << later << endl;
        return max(former, later);
    }
}

int main(){
    int a[LIMIT];
    cin >> n;
    rep(i, n) cin >> a[i];
    ans = findMax(a, 0, n);
    cout << ans << endl;
    return 0;
}