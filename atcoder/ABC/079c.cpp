#include <cstdio>
char s[4];
int main ()
{
  scanf("%s",s);
  int a=s[0]-’0’,b=s[1]-’0’,c=s[2]-’0’,d=s[3]-’0’;
  if (a -b -c - d ==7) printf ("%d-%d-%d-%d=7\n",a ,b ,c , d );
  else if (a-b-c+d ==7) printf ("%d-%d-%d+%d=7\n" ,a ,b ,c , d );
  else if (a-b+c - d ==7) printf ("%d-%d+%d-%d=7\n" ,a ,b ,c , d );
  else if (a - b + c + d ==7) printf ("%d-%d+%d+%d=7\n" ,a ,b ,c , d );
  else if ( a +b -c - d ==7) printf ("%d+%d-%d-%d=7\n" ,a ,b ,c , d );
  else if ( a +b - c + d ==7) printf ("%d+%d-%d+%d=7\n" ,a ,b ,c , d );
  else if ( a + b +c - d ==7) printf ("%d+%d+%d-%d=7\n" ,a ,b ,c , d );
  else if ( a + b + c + d ==7) printf ("%d+%d+%d+%d=7\n" ,a ,b ,c , d );
}
