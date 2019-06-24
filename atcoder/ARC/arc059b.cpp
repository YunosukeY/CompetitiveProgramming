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
  string s; cin >> s;

  rep(i,s.size() - 1)
    if(s[i] == s[i + 1]){
      cout << i + 1 << " " << i + 2 << endl;;
      return 0;
    }

  rep(i,s.size() - 2)
    if(s[i] == s[i + 2]){
      cout << i  + 1 << " " << i + 3 << endl;
      return 0;
    }

  cout << "-1 -1\n";
}
