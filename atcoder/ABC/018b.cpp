#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

main(){
  string s;
  int n;
  cin >> s >> n;
  string s1,s2,s3;
  int l,r;
  rep(i,n){
    cin >> l >> r;
    l--; r--;
    s1 = s.substr(0,l);
    s2 = s.substr(l,r-l+1);
    s3 = s.substr(r+1,s.size()-r-1);
    //cout << s1 << " " << s2 << " " << s3 << endl;
    reverse(all(s2));
    s=s1+s2+s3;
    //cout << s << endl;
  }
  cout << s << endl;
}
