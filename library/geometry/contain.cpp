// 多角形と点の包含判定
bool containGP(const G& g, const P& p){
  double sum = 0.0;
  int n = g.size();
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;
    if(intersectSP(L(g[i], g[j]-g[i]), p))
      return true;
    sum += arg((g[j]-p)/(g[i]-p));
  }
  return (abs(sum) > 1);
}
