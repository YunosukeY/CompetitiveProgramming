#include "plot.hpp"

int main(){
  P p0{2,2}, p1{-5,-1}, p2{-1,-4}, p3{0,0}, p4{1,3}, p5{4,4};
  L l(p1,p2);
  G g{p3,p4,p5};
  C c(p3,2);
  plot(p0, l, g, c);
}
