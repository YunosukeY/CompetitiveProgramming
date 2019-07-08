// 直線の交点
P crosspoint(const L &l, const L &m){
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) return P(nan(""),nan("")); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

// 円同士の交点
// 1点または2点で交わることを要求する
// 交わらない場合はnanを返す
pair<P, P> crosspointCC(const C& c1, const C& c2){
  double d = abs(c1.p - c2.p);
  double rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
  double rs = sqrt(c1.r*c1.r - rc*rc);
  P diff((c2.p - c1.p) / d);
  return make_pair(c1.p + diff * P(rc, rs), c1.p + diff * P(rc, -rs));
}

// 円と直線の交点
vector<P> crosspointCL(const C& c, const L& l){
  P h(projection(l, c.p));
  double d = abs(h - c.p);
  vector<P> res;
  if(d < c.r - EPS){
    P dir = l[1] - l[0];
    P x(dir / abs(dir) * sqrt(c.r*c.r - d*d));
    res.push_back(h + x);
    res.push_back(h - x);
  }else if(d < c.r + EPS){
    res.push_back(h);
  }
  return res;
}

// 点を通る円への接線
vector<L> tangentCP(const C &c, const P &p){
  vector<L> ret;
  P vect(c.p - p);
  double d = abs(vect);
  double l = sqrt(d*d-c.r*c.r);
  if(isnan(l)) return ret;
  P v1(vect * P(l / d,  c.r / d));
  P v2(vect * P(l / d, -c.r / d));
  ret.push_back(L(p, p+v1));
  if(l > EPS)
    ret.push_back(L(p, p+v2));
  return ret;
}

// 点を通る凸多角形への接線
bool solveT(const G &g, const P &p, int ok, int mid, bool isRight){
  int n = g.size();
  int a = ccw(g[(ok-1+n)%n],g[ok],p), b = ccw(g[(mid-1+n)%n],g[mid%n],p);
  bool f;
  if(isRight)
    f = a != -1 and (b != 1 or ccw(g[ok],g[mid%n],p) != 1);
  else{
    int c = ccw(g[(ok-1+n)%n],g[(mid-1+n)%n],p);
    f = (a != 1 and c != -1) or (b != -1 and c != 1);
  }
  return f;
}
int bsT(const G &g, const P &p, int _ok, int _ng, bool isRight){
  int ok = _ok;
  int ng = _ng;

  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;
    if(solveT(g, p, ok, mid, isRight)){
      ng = mid;
    }else{
      ok = mid;
    }
  }
  return ok;
}
vector<L> tangentGP(const G &g, const P &p){
  vector<L> res;
  rep(i,2){
    int pos = bsT(g,p,0,g.size()+1,i);
    res.push_back(L(p,g[pos]));
  }
  return res;
}
