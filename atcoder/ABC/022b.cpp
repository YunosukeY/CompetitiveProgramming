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

template < typename T > string to_string(T& n){
  ostringstream stm ;
  stm << n ;
  return stm.str() ;
}

main(){
  int n,a,size,count=0;
  set<int> st;
  cin >> n;
  rep(i,n){
    cin >> a;
    size=st.size();
    st.insert(a);
    if(size==st.size()) count++;
  }
  cout << count << endl;
}
