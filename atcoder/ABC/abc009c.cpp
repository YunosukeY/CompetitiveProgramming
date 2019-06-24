#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

main(){
  int n, k; cin >> n >> k;
  vector<char> s(n), t(n), remain(n);
  vi used(n);
  rep(i,n){
    cin >> s[i];
    remain[i] = s[i];
  }
  
  sort(all(remain));
  int dif = 0; // i文字まで違う個数

  rep(i,n) rep(j,remain.size()){
    int tmp = dif;
    rep(k,used.size()) used[k] = 0;
    
    t[i] = remain[j]; // 置いてみる
    //rep(k,n) cout << t[k]; cout << endl;
    used[j] = 1;
    if(t[i] != s[i]) tmp++;

    FOR(k,i+1,n){ // 残りに対して
      bool f = false;
      rep(l,remain.size())
	if(s[k] == remain[l] and used[l] == 0){ // 同じものが残っていれば置く　
	  used[l] = 1;
	  f = true;
	  break;
	}
      if(f == false) tmp++; // 置けるものはない
    }
    
    if(tmp <= k){
      //cout << dif << tmp << endl;
      t[i] = remain[j];
      if(s[i] != t[i]) dif++;
      remain.erase(remain.begin() + j);
      used.erase(used.begin() + j);
      break;
    }
  }
  rep(i,n) cout << t[i]; cout << endl;
}
