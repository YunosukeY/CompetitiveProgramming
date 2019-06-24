#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
bool eq(const double &a, const double &b) { return abs(a-b)<eps; }

struct point {
  double x, y;
  point():x(0),y(0) {}
  point(double _x, double _y):x(_x),y(_y) {}

  point operator+=(const point &p) { x+=p.x; y+=p.y; return *this; }
  point operator-=(const point &p) { x-=p.x; y-=p.y; return *this; }
  point operator*=(const point &p) { double tx = x; x=x*p.x-y*p.y; y=y*p.x+tx*p.y; return *this; }
  point operator*=(const double &d) { x*=d; y*=d; return *this; }
  point operator/=(const double &d) { x/=d; y/=d; return *this; }
  point operator+(const point &p) const { return point(*this)+=p; }
  point operator-(const point &p) const { return point(*this)-=p; }
  point operator*(const double &d) const { return point(*this)*=d; }
  point operator*(const point &p) const { return point(*this)*=p; }
  point operator/(const double &d) const { return point(*this)/=d; }
  point operator-() const { return point(-x,-y); }
  bool operator<(const point &p) const { return std::abs(x- p.x)>eps ? x < p.x-eps : y < p.y-eps; }
  bool operator==(const point &p) const { return std::abs(x-p.x)<eps and std::abs(y-p.y)<eps; }
  bool operator!=(const point &p) const { return !(point(*this)==p); }

  double norm() const { return x*x+y*y; }
  double abs() const { return sqrt(norm()); }
  double arg() const { return atan2(y, x); }
  double dot(const point &p) const { return x*p.x+y*p.y; }
  double cross(const point &p) const { return x*p.y-y*p.x; }
  double det(const point &p) const { return x*p.y-y*p.x; }
  point proj(const point &p) const { double k = dot(p)/norm(); return point(x*k,y*k); }
};
point operator*(const double &d, const point &p) { point q = p*d; return q; }
ostream &operator<<(std::ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; return os; }

point polar(const double &r, const double &th) { return point(r*cos(th),r*sin(th)); }
double abs(const point &p) { return p.abs(); }
double norm(const point &p) { return p.norm(); }
double dot(const point &a, const point &b) { return a.dot(b); }
double cross(const point &a, const point &b) { return a.cross(b); }
double det(const point &a, const point &b) { return a.det(b); }
double arg(const point &a) { return a.arg(); }
/*
 *           1
 *  ------------------
 *    -2 |a  0  b| 2
 *  ------------------
 *          -1
 */
int ccw(point a, point b, point c){
    b -= a, c -= a;
    if (b.cross(c) > eps)        return +1;
    if (b.cross(c) < -eps)       return -1;
    if (b.dot(c) < -eps)         return -2; // c -- a -- b
    if (b.norm() < c.norm()-eps) return +2; // a -- b -- c
    return 0;
}

vector<point> convex_hull(std::vector<point> ps) {
  int n = ps.size(), k = 0;
  if(n < 3) return ps;
  sort(begin(ps),end(ps));
  vector<point> ret(2*n);

  for (int i = 0; i < n; ret[k++] = ps[i++])
    while (k >= 2 and ccw(ret[k-2], ret[k-1], ps[i]) < 1) k--;
  for (int i = n-2, t = k+1; i >= 0; ret[k++] = ps[i--])
    while (k >= t and ccw(ret[k-2], ret[k-1], ps[i]) < 1) k--;
  ret.resize(k-1);
  return ret;
}

int main(){
}
