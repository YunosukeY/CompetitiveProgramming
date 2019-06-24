#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;i++)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;i++)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;i--)
typedef long long ll;

vector<int> prime(int n){
  // n以下の素数を要素に持つviを返す
  // 時間 O(n ln ln n)
  // 答えのサイズ n / ln n

  vector<bool> isprime(n+1,true);
  vector<int> ans;
  isprime[0] = isprime[1] = false;
  FOR(i,2,n+1)
    if(isprime[i]){
      ans.push_back(i);
      for(int j = 2 * i; j <= n; j += i) isprime[j] = false;
    }
  return ans;
}

// using function prime
// たぶん遅い
map<int,int> pf(int n){ // nの素因数分解
  vector<int> p = prime(n);
  map<int,int> mp;
  rep(i,p.size()){
    if(n == 1 or p[i] > sqrt(n)) break;
    while(1){
      if(n % p[i] == 0){
	n /= p[i];
	mp[p[i]]++;
      }else break;
    }
  }
  if(n != 1) mp[n]++;
  return mp;
}

map<int,int> pf(int n){
  map<int,int> res;
  FOR(i,2,sqrt(n)+1){
    if(n == 1) break;
    while(n%i == 0){
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n]++;
  return res;
}

vector<int> divisor(int n){ // O(√n)約数列挙
  vector<int> res;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i * i != n) res.push_back(n/i);
    }
  }
  // sort(res.begin(),res.end());
  return res;
}

main(){
  int n,k; cin >> n >> k;
  auto mp = pf(k);
  for(auto x : mp)
    if(30 % x.fst){
      // kが2,3,5以外の素因数を持つ
      cout << 0 << endl;
      return 0;
    }

  // dp[i+1][j][k][l] : i回振った時,2がj回,3がl回,5がl回出ている場合の数
  vector<vector<vvi>> dp(n+1,vector<vvi>(mp[2],vvi(mp[3],vi(mp[5]))));
  dp[0][0][0][0] = 1;
  
}
