#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
  int a,b,c; cin >> a >> b >> c;
  if(a + b >= c) cout << "Yes\n";
  else cout << "No\n";
}
