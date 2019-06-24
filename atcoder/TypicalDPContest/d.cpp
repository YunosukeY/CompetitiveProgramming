#include<bits/stdc++.h>
using namespace std;

#define int ll
#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define fst first
#define snd second
using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;

map<int,int> pf(int n){ // nの素因数分解
  map<int,int> res;
  while(n%2==0){
    res[2]++;
    n /= 2;
  }
  while(n%3==0){
    res[3]++;
    n /= 3;
  }
  while(n%5==0){
    res[5]++;
    n /= 5;
  }
  if(n != 1) res[n]++;
  return res;
}

main(){
  int n,a; cin >> n >> a;
  auto mp = pf(a);
  for(auto x : mp)
    if(30 % x.fst){
      // kが2,3,5以外の素因数を持つ
      cout << 0 << endl;
      return 0;
    }
  
  int c2 = mp[2], c3 = mp[3], c5 = mp[5];
  // dp[i+1][j][k][l] : i回振った時,2がj回,3がl回,5がl回出ている場合の数
  vector<vector<vector<double>>> now(c2+1,vector<vector<double>>(c3+1,vector<double>(c5+1)));
  now[0][0][0] = 1;

  // i = 2^d[i][0]*3^d[i][1]*5^d[i][2]
  vvi d = {{0,0,0},{1,0,0},{0,1,0},{2,0,0},{0,0,1},{1,1,0}};
  rep(i,n){
    vector<vector<vector<double>>> nxt(c2+1,vector<vector<double>>(c3+1,vector<double>(c5+1)));
    
    rep(j,c2+1) rep(k,c3+1) rep(l,c5+1){
      rep(m,d.size()){
	int tmpj = min(c2, j+d[m][0]), tmpk = min(c3, k+d[m][1]), tmpl = min(c5, l+d[m][2]);
	nxt[tmpj][tmpk][tmpl] += now[j][k][l] / 6;
      }
    }
    now = move(nxt);
  }
  
  printf("%.10f\n", now[c2][c3][c5] );
}
