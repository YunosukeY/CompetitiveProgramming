#include <bits/stdc++.h>
#include "../test.cpp"
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const double EPS = 1e-8;
//const double INF = 1e12;
// 点
typedef complex<double> P;

// 外積
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
// 内積
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

// 直線
// 線分は端点を入れる
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

// 曲がる方向
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // 反時計周り
  if (cross(b, c) < 0)   return -1;       // 時計回り
  if (dot(b, c) < 0)     return +2;       // c--a--b の順に一直線
  if (norm(b) < norm(c)) return -2;       // a--b--c の順に一直線
  return 0;
}

// 点の線への射影
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

// 線分と点の交差判定
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

// 線分同士の交差判定
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

// 線分と点の距離
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

// 線分同士の距離
double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

// 点同士の距離
double distancePP(const P &p, const P &q){
  return abs(p-q);
}

// fを中心にpをdeg回転
P rotateP(P p, const P &f, double deg){
  double dis = distancePP(p,f);
  deg += arg(p-f);
  p = f + P(dis*cos(deg),dis*sin(deg));
  return p;
}

// fを中心にlをdeg回転
L rotateL(L l, const P &f, double deg){
  L res{f,f};
  rep(i,l.size()) res[i] = rotateP(l[i],f,deg);
  return res;
}
  
using Cost = double;
class node {
public:
  int v;
  Cost d;
  node(int _a, Cost _b):v(_a),d(_b){}
  bool operator<(const node &n) const { return d > n.d; }
};
class edge {
public:
  int to;
  Cost d;
  edge(){}
  edge(int _to, Cost _d):to(_to),d(_d){}
};
class dijkstra{
public:
  vector<vector<edge>> G;
  vector<Cost> dist;

  dijkstra(int s,int t,const vector<vector<edge>> &_G):G(_G){ // sからtへの最短経路
    dist.resize(G.size(),INF);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      int v = que.top().v;
      Cost d = que.top().d;
      que.pop();
      if(v == t) break;
      
      rep(i, G[v].size()){
	Cost tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }
};

int main(){
  int n, m, l;
  while(cin >> n >> m >> l, n){
    m--; l--;
    
    // 星の5本線を格納する構造
    vector<vector<L>> stars(n);
    rep(i,n){
      double x, y, a, r;
      cin >> x >> y >> a >> r;

      double d = M_PI * a / 180.0;
      double diff = M_PI * 72.0 / 180.0;
      P c(x,y),def1(x,y+r),def2 = rotateP(def1,c,2*diff);
      L def{def1,def2}; // 基準となる線
      // 基準を回転させて星を作る
      rep(j,5){
	stars[i].push_back(rotateL(def,c,d));
	d += diff;
      }
    }
    plot(stars[0][0],stars[0][1],stars[0][2],stars[0][3],stars[0][4],stars[1][0],stars[1][1],stars[1][2],stars[1][3],stars[1][4],stars[2][0],stars[2][1],stars[2][2],stars[2][3],stars[2][4]);

    // グラフを作る
    vector<vector<edge>> g(n);
    rep(i,n) FOR(j,i+1,n){
      double d = INF;
      rep(x,5) rep(y,5) chmin(d,distanceSS(stars[i][x],stars[j][y]));
      g[i].push_back(edge(j,d));
      g[j].push_back(edge(i,d));
    }
    
    // 最短経路
    dijkstra dijk(m,l,g);
    //dump(dijk.dist);
    printf("%.10f\n",dijk.dist[l]);
  }
}
