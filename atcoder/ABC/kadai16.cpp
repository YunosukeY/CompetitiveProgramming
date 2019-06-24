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
const int LIMIT = 100;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int m, n;
int ans;

int combination(int n, int r){
    if(n == 0) return 1;
    else if(r == 0) return 1;
    else if(n == r) return 1;
    else return combination(n - 1, r) + combination(n - 1, r - 1);
}

int main(){
    cin >> m >> n;
    ans = combination(m - 1, n - 1);
    cout << ans << endl;
    return 0;
}