#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll mod = 1000000007;

ll powmod(ll a, ll b, ll p){//a^b(mod p)
  if(b == 0) return 1;
  if(b%2 == 0){
    ll d = powmod(a,b/2,p);
    return (d*d)%p;
  }else return (a*powmod(a,b-1,p))%p;
}

ll maxs(ll a,ll b){
  int av = 0,bv = 0;
  string sa = to_string(a),sb = to_string(b);
  rep(i,sa.size()) av += (sa[i] - '0');
  rep(i,sb.size()) bv += (sb[i] - '0');
  if(av >= bv) return a;
  else return b;
}

main(){
  string s; cin >> s;
  ll siz = s.size();
  ll tmp = (s[siz-1] - '0');
  if(siz == 1){
    cout << s << endl;
    return 0;
  }
  /*
  bool flag = true;
  rep(i,siz) if(s[i] != '9') flag = false;
  if(flag){
    cout << 9 * siz << endl;
    return 0;
  }
  */
  ROF(i,siz-1,0){
    //cout << tmp << endl;
    if(s[i] == '0') continue;
    ll a = (s[i] - '0') * pow(10,siz-i-1);
    //cout << a << endl;
    tmp = maxs(a + tmp, a - 1);
  }
  int ansv = 0;
  string anss = to_string(tmp);
  rep(i,anss.size()) ansv += (anss[i] - '0');
  cout << ansv << endl;
}
