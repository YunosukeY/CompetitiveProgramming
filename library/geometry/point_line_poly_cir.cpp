// 基本要素

const double EPS = 1e-8;
const double INF = 1e12;
// 点
using P =  complex<double>;
namespace std {
  bool operator < (const P& a, const P& b) { // 辞書順
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
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

// 多角形
// 頂点は反時計にすること
using G = vector<P>;

// 円
struct C {
  P p; double r;
  C(const P &p_, double r_) : p(p_), r(r_) { }
};
