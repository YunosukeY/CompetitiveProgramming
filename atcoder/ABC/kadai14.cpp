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

int n;
string s;
string c[10];
int ans;

int main(){
    c[1] = ".,!? ";
    c[2] = "abc";
    c[3] = "def";
    c[4] = "ghi";
    c[5] = "jkl";
    c[6] = "mno";
    c[7] = "pqrs";
    c[8] = "tuv";
    c[9] = "wxyz";
    cin >> n;
    rep(i, n){
        string str;
        cin >> str;
        int num = 0;
        int cnt = 0;
        rep(j, str.size()){
            if(str[j] == '0'){
                if(num != 0){
                    cout << c[num][(cnt - 1) % c[num].size()];
                    num = 0;
                }
                cnt = 0;
            }else{
                num = str[j] - '0';
                cnt++;
            }
        }
        cout << endl;
    }
    return 0;
}