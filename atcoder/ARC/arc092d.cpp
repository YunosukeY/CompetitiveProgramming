#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
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

const int maxsize = 200000; // 2^6*5^5
const int bl = 16; // ブロック化のサイズ

int a[maxsize],b[maxsize],tmp[bl],add[bl];
// グローバル変数は0で初期化される
// 0はxorの単位元

int main(){
  // int型はscanfよりcin高速化のほうが早い
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  int ans = 0;
  
  rep(i,maxsize){
    for(int jb = 0; jb < maxsize; jb += bl){
      int lubj = jb + bl;
      for(int j = jb, k = 0; j < lubj; j++, k++){
	add[k] = a[i] + b[j];
      }
      for(int j = jb, k = 0; j < lubj; j++, k++){
	tmp[k] ^= add[k];;
      }
    }
  }
  rep(k,bl) ans ^= tmp[k];
  
  cout << ans << endl;
}
