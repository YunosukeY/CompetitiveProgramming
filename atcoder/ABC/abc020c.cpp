#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumlate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

#define int ll

main(){
  //input
  int h,w,t; cin >> h >> w >> t;
  int size = h * w;
  vs s(h); int sx,sy,gx,gy;
  rep(i,h){
    cin >> s[i];
    rep(j,w)
      if(s[i][j] == 'S'){
	sx = i; sy = j;
      }else if(s[i][j] == 'G'){
	gx = i; gy = j;
      }
  }
  int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

  //binary search
  int low = 1, high = t, mid;
  while(1){
    mid = (low + high) / 2;
    
    //コストmidに対するadj matrix
    auto g = vector<vector<ll>>(size,vector<ll>(size,1<<30));
    rep(i,h) rep(j,w){ //(i,j)への移動コスト
      int cost;
      if(s[i][j] == '#') cost = mid;
      else cost = 1;
      int now =i*w+j, adj, adjx, adjy;
      //printf("(%d,%d)'s cost is %d\n",i,j,cost);
      rep(k,4){
	adjx = i + dx[k];
	adjy = j + dy[k];
	//printf("now, looking (%d,%d)\n",adjx,adjy);
	if((0 <= adjx) and (adjx < h) and (0 <= adjy) and (adjy < w)){
	  adj = adjx*w+adjy;
	  //printf("(%d(%d,%d)->%d(%d,%d) : %d\n",now,i,j,adj,adjx,adjy,cost);
	  g[adj][now] = cost;
	}
      }
      rep(k,size) g[k][k] = 0;
    }
    /*
    rep(i,size){
      rep(j,size) cout << g[i][j] << " ";
      cout << endl;
    }
    */
    
    //ワーシャルフロイド
    rep(k,size) rep(i,size) rep(j,size) g[i][j] = min(g[i][j],g[i][k]+g[k][j]);

    //cout << mid << " " << g[sx*w+sy][gx*w+gy] << endl;
    if(g[sx*w+sy][gx*w+gy] <= t) low = mid;
    else high = mid;

    if(high - low == 1) break;
  }

  cout << low << endl;
}
