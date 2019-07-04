// pをfを中心にdeg回転
P rotateP(P p, const P &f, double deg){
  double dis = distancePP(p,f);
  deg += arg(p-f);
  p = f + P(dis*cos(deg),dis*sin(deg));
  return p;
}

// lをfを中心にdeg回転
L rotateL(L l, const P &f, double deg){
  L res(l);
  rep(i,l.size()) res[i] = rotateP(l[i],f,deg);
  return res;
}

// gをfを中心にdeg回転
G rotateL(G g, const P &f, double deg){
  G res(g);
  rep(i,g.size()) res[i] = rotateP(g[i],f,deg);
  return res;
}
