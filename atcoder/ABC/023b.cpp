#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)
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
  int i,j;
  int n;
  string s;
  cin >> n >> s;
  int flag=0;//true
  if(n%2==0 || s[n/2]!='b') flag=1;//false
  else{
    if(s=="b") flag=0;
    else if(s=="abc") flag=0;
    else if(s=="cabca") flag=0;
    else if(s.size()>5 && s[0]<'d' && s[1]<'d' && s[2]< 'd' && s[0]!=s[1] && s[1]!=s[2] && s[2]!=s[0] && 'a'<=s[0] && 'a'<=s[1] && 'a'<=s[2]){
      rep(i,n/3-1){
	if(s[3*i]!=s[3*i+3]){
	  flag=1;
	  break;
	}
	if(s[3*i+1]!=s[3*i+4]){
	  flag=1;
	  break;
	}
	if(s[3*i+2]!=s[3*i+5]){
	  flag=1;
	  break;
	}
      }
      FOR(j,(i*3)+3,n){
	if(s[i]!=s[i-3]){
	  flag=1;
	  break;
	}
      }
    }else flag=1;
  }
  if(flag) cout << -1;
  else cout << n/2;
	       cout << endl;
}
