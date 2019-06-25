// 三角形の重心
P centroidT(const G &t){
  return (t[0]+t[1]+t[2])/3.0;
}

// 多角形の重心
P centroidG(const G &g){
  P res;
  double a = 0;
  FOR(i,1,g.size()-1){
    G tmp{g[0],g[i],g[i+1]};    
    res += area2(tmp) * (tmp[0]+tmp[1]+tmp[2])/3.0;
    a += area2(tmp);
  }
  res /= a;
  return res;
}

// 外心
P circumcenter(const G &t){
  P res;
  double s = 0;
  rep(i,3){
    double deg = 2 * (arg(t[(i+2)%3]-t[i])-arg(t[(i+1)%3]-t[i]));
    res += sin(deg) * t[i];
    s += sin(deg);
  }
  res /= s;
  return res;
}
    
// 内心
P innercenter(const G &t){
  P res;
  double s = 0;
  rep(i,3){
    res += abs(t[i])*t[i];
    s += abs(t[i]);
  }
  res /= s;
  return res;
}

// 垂心
P othrocenter(const G &t){
  P res;
  double s = 0;
  rep(i,3){
    double deg = arg(t[(i+2)%3]-t[i])-arg(t[(i+1)%3]-t[i]);
    res += tan(deg) * t[i];
    s += tan(deg);
  }
  res /= s;
  return res;
}
