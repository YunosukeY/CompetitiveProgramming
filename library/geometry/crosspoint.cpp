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
  P diff = (c2.p - c1.p) / d;
  return make_pair(c1.p + diff * P(rc, rs), c1.p + diff * P(rc, -rs));
}

// 円と直線の交点
vector<P> crosspointCL(const C& c, const L& l){
  P h = perf(l, c.p);
  double d = abs(h - c.p);
  vector<P> res;
  if(d < c.r - EPS){
    P x = l.dir / abs(l.dir) * sqrt(c.r*c.r - d*d);
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
  P vect = c.p - p;
  double d = abs(vect);
  double l = sqrt(d*d-c.r*c.r);
  if(isnan(l)) return ret;
  P v1 = vect * P(l / d,  c.r / d);
  P v2 = vect * P(l / d, -c.r / d);
  ret.push_back(L(p, p+v1));
  if(l > EPS)
    ret.push_back(L(p, p+v2));
  return ret;
}
