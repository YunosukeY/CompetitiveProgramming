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
  vi color(1000001);
  int n; cin >> n;
  int a,b;
  rep(i,n){
    cin >> a >> b;
    color[a]++;
    color[b+1]--;
  }
  rep(i,1000000) color[i+1]+=color[i];
  cout << *max_element(all(color)) << endl;
}
