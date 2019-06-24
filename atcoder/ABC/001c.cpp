#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) For(i,0,n)
#define For(i,a,b) for(i=(a);i<(b);i++)
typedef vector<int> vi;
typedef vector< vi > vii;

int main(){
  int i,j;
  int deg,dis;
  cin >> deg >> dis;
  string s;
  int w;
  dis=(dis+3)/6;
  deg*=10;
  if(dis <= 2) w=0;
  else if(dis <= 15) w=1;
  else if(dis <= 33) w=2;
  else if(dis <= 54) w=3;
  else if(dis <= 79) w=4;
  else if(dis <= 107) w=5;
  else if(dis <= 138) w=6;
  else if(dis <= 171) w=7;
  else if(dis <= 207) w=8;
  else if(dis <= 244) w=9;
  else if(dis <= 284) w=10;
  else if(dis <= 326) w=11;
  else w=12;

  if(w==0) s="c";
  else{
    if(1125<=deg && deg<3375) s="NNE";
    else if(3375<=deg && deg<5625) s="NE";
    else if(5625<=deg && deg<7825) s="ENE";
    else if(7825<=deg && deg<10125) s="E";
    else if(10125<=deg && deg<12375) s="ESE";
    else if(12375<=deg && deg<14625) s="SE";
    else if(14625<=deg && deg<16875) s="SSE";
    else if(16875<=deg && deg<19125) s="S";
    else if(19125<=deg && deg<21375) s="SSW";
    else if(21375<=deg && deg<23625) s="SW";
    else if(23625<=deg && deg<25875) s="WSW";
    else if(25875<=deg && deg<28125) s="W";
    else if(28125<=deg && deg<30375) s="WNW";
    else if(30375<=deg && deg<32625) s="NW";
    else if(32625<=deg && deg<34875) s="NNW";
    else s="N";
  }

  cout << s << " " << w << endl;
  
  return 0;
}
