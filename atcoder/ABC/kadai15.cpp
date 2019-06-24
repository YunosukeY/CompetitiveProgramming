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
const int LIMIT = 2000;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n;
int a[LIMIT];
int q;
int m_i[LIMIT];

bool judge(int i, int m){
    if(m == 0) return true;
    if(i >= n) return false;
    return judge(i + 1, m) || judge(i + 1, m - a[i]);
}
int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    cin >> q;
    rep(i, q) cin >> m_i[i];
    rep(i, q){
        if(judge(0, m_i[i])) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}