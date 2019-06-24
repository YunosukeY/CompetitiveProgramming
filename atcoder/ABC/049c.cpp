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
  string s; cin >> s;
  string t; int head=0;
  while(1){
    if(head == s.size()) break;
    cout << s.substr(head,6) << endl;
    if(s.substr(head,6) == "eraser") head += 6;
    else if(s.substr(head,5) == "erase") head += 5;
    else if(s.substr(head,7) == "dreamer") head += 7;
    else if(s.substr(head,5) == "dream") head += 5;
    else{
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
