#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
typedef vector<int> vi;
typedef vector< vi > vii;
typedef vector<string> vs;
typedef vector< vs > vss;
typedef pair<int,int> pii;

main(){
  int h,w,t;
  cin >> h >> w >> t;
  vss s(h);
  rep(i,h) s[i].resize(w);
  pii st,gl;
  rep(i,h) rep(j,w){
    cin >> s[i][j];
    if(s[i][j]=="S"){
      st.first=j;
      st.second=i;
    }else if(s[i][j]=="G"){
      gl.first=j;
      gl.second=i;
    }
  }

  
}
