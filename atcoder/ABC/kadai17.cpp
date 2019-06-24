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
const int LIMIT = 1 << 20;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int m, n;
string s;
int ans;
int bit[LIMIT];

int main(){
    cin >> n >> m;
    rep(i, 1 << n) bit[i] = i;
    rep(i, 1 << n){
        int cnt = 0;
        rep(j, n){
            if((bit[i] >> j) & 1){
                cnt++;
                if(cnt >= m){
                    ans++;
                    break;
                }
            }
            else cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}