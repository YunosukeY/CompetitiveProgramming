#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)

const double EPS = 1e-8;
// 点
typedef complex<double> P;
namespace std {
  bool isnan(const P&p){
    return isnan(p.real()) or isnan(p.imag());
  }
}

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

// 円
struct C {
  P p; double r;
  C(const P &p_, double r_) : p(p_), r(r_) { }
};

// 交差判定
// 直線同士
bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
    abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}

// 直線の交点
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) return P(nan(""),nan("")); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

// 点の線への射影
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

// 直線と点の距離
double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}

// 直線lを垂線右方向にdis移動
L slideL(L l, double dis){
  double deg = arg(l[1]-l[0]);
  P p = P(dis*sin(deg),-dis*cos(deg));
  l[0] += p;
  l[1] += p;
  return l;
}

signed main(){
  int n;
  double w,h,r;
  while(cin >> w >> h >> n >> r, n){
    // input
    vector<L> ls;
    vector<double> ts(n);
    rep(i,n){
      double a,b,c,d;
      cin >> a >> b >> c >> d;
      P x{a,b},y{c,d};
      ls.emplace_back(x,y);
      cin >> ts[i];
    }

    // 候補を列挙
    vector<P> can;
    // 四隅を追加
    can.push_back({r,r});
    can.push_back({r,h-r});
    can.push_back({w-r,r});
    can.push_back({w-r,h-r});
    // 2線に接する点を追加
    rep(i,n) FOR(j,i+1,n){
      // 交差しない
      if(not intersectLL(ls[i],ls[j])) continue;

      // 元の直線からr+t平行移動した直線l,rを用意
      // 交点が候補の候補となる
      L li = slideL(ls[i],-r-ts[i]), ri = slideL(ls[i],r+ts[i]);
      L lj = slideL(ls[j],-r-ts[j]), rj = slideL(ls[j],r+ts[j]);
      vector<P> tmpcan;
      tmpcan.push_back(crosspoint(li,lj));
      tmpcan.push_back(crosspoint(li,rj));
      tmpcan.push_back(crosspoint(ri,lj));
      tmpcan.push_back(crosspoint(ri,rj));

      // 枠の中にあるなら候補
      auto isin = [&](const P &p){
	return r < p.real()+EPS and p.real()-EPS < w-r and r < p.imag()+EPS and p.imag()-EPS < h-r;
      };
      rep(k,4){
	if((not isnan(tmpcan[k])) and isin(tmpcan[k]))
	  can.push_back(tmpcan[k]);
      }
    }

    // 各候補が全ての線からr+t以上離れているか
    bool f = false;
    rep(i,can.size()){
      bool g = true;
      rep(j,n){
	double d = distanceLP(ls[j],can[i]);
	if(r + ts[j] > d + EPS){
	  g = false;
	  break;
	}
      }
      if(g){
	f = true;
	break;
      }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
