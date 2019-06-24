#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  int n; cin >> n;
  string s;
  vi min(26,100);
  rep(i,n){
    vi in(26);
    cin >> s;
    rep(j,s.size()) in[s[j]-'a']++;
    rep(j,26) if(min[j]>in[j]) min[j] = in[j];
  }
  rep(i,26) rep(j,min[i]) cout << (char)(i+'a');
  cout << endl;
}
