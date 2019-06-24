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

pii mp[90001];
int cost[90001];

main(){
  int h,w,d; cin >> h >> w >> d;
  int a;
  rep(i,h) rep(j,w){
    cin >> a;
    mp[a] = pii(i,j);
  }
  FOR(i,1,d+1) cost[i] = 0;
  FOR(i,d+1,h*w+1) cost[i] = cost[i-d] + abs(mp[i].fst-mp[i-d].fst) + abs(mp[i].snd-mp[i-d].snd);
  int q; cin >> q;
  int l,r;
  rep(i,q){
    cin >> l >> r;
    printf("%d\n",cost[r]-cost[l]);
  }
}
