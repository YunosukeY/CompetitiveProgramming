// a->b->cという折れ線がどうなっているか
int ccw(P a, P b, P c){
  b -= a; c -= a;
  if(cross(b, c) > 0)   return +1;       // 反時計周り
  if(cross(b, c) < 0)   return -1;       // 時計回り
  if(dot(b, c) < 0)     return +2;       // c--a--b の順に一直線
  if(norm(b) < norm(c)) return -2;       // a--b--c の順に一直線, a==bも含む
  return 0;                              // a--c--b の順に一直線, b==cも含む
}
