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
  int n,a,b,k;
  cin >> n >> a >> b >> k;
  int in;
  set<int> st;
  st.insert(a);
  st.insert(b);
  rep(i,k){
    cin >> in;
    st.insert(in);
  }
  //cout << st.size() << endl;
  if(k+2==st.size()) cout << "YES";
  else cout << "NO";
  cout << endl;
}
