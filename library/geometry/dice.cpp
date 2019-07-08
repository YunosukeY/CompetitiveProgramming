struct die_t{
  int top, front, right, left, back, bottom;
};

#define rotate_swap(x,a,b,c,d) swap(x.a, x.b); swap(x.b, x.c); swap(x.c, x.d);
// rightがtopになるよう回転
void rotate_right(die_t& x){ rotate_swap(x,top,left,bottom,right); }
void rotate_left(die_t& x){ rotate_swap(x,top,right,bottom,left); }
void rotate_front(die_t& x){ rotate_swap(x,top,back,bottom,front); }
void rotate_back(die_t& x){ rotate_swap(x,top,front,bottom,back); }
// 上から見て時計回りに回転
void rotate_cw(die_t& x){ rotate_swap(x,back,left,front,right); }
void rotate_ccw(die_t& x){ rotate_swap(x,back,right,front,left); }

void generate_all(){
  rep(i, 6){ // top 6種類
    rep(j, 4){　// front 4種類
      rotate_cw(x);
    }
    (i%2 == 0 ? rotate_right : rotate_front)(x);
  }
}
