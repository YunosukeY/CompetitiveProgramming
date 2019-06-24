#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  string s,t; cin >> s >> t;
  vector<char> x(s.size()),y(t.size());
  rep(i,s.size()) x[i]=s[i];
  rep(i,t.size()) y[i]=t[i];
  sort(all(x));
  sort(y.rbegin(),y.rend());
  string u,v;
  rep(i,s.size()) u+=x[i];
  rep(i,t.size()) v+=y[i];
  if(u<v) cout << "Yes";
  else cout << "No";
  cout << endl;
}
