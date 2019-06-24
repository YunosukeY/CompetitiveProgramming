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

double noudo(int a,int b){
  return double(100 * b) / double(a + b);
}

main(){
  int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;

  double maxnoudo = 0;
  int x,y;

  FOR(i,1,f) FOR(j,1,f){ // i:水,j:砂糖
    if(i % 100 != 0 or i + j > f) continue;
    // iを作れるか
    bool f = false;
    rep(k,(i/100)+1)
      if(i >= a*k*100 and (i - a * k * 100) % (b * 100) == 0) f = true;
    if(!f) continue;
    f = false;
    // jが作れるか
    rep(k,j+1)
      if(j >= c * k and (j - c * k) % d == 0) f = true;
    if(!f) continue;
    if(noudo(i,j) <= noudo(100,e) and noudo(i,j) > maxnoudo){
      maxnoudo = noudo(i,j);
      x = i;
      y = j;
    }
  }

  if(maxnoudo == 0) cout << 100 * a << " " << 0 << endl;
  else cout << x+y << " " << y << endl;
}
