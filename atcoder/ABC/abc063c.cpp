#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
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


main(){
  int n; cin >> n;
  vi s(n); rep(i,n) cin >> s[i];
  sort(all(s));
  int sum = SUM(s);
  if(sum % 10 != 0){
    cout << sum << endl;;
    return 0;
  }else
    rep(i,n)
      if(s[i] % 10 != 0){
	cout << sum - s[i] << endl;
	return 0;
      }

  cout << 0 << endl;
}
