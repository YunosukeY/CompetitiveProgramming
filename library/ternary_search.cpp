// doubleの時はloop以外をdoubleにするだけ

#define maxLoop 1000

ll f(ll x){} // 最大値を求めたい上に凸な関数

ll search(ll left, ll right){
  for (ll loop = 0; loop < maxLoop; ++loop){
    if (f((left * 2 + right) / 3) > f((left + right * 2) / 3)){
      right = (left + right * 2) / 3;
    } else {
      left = (left * 2 + right) / 3;
    }
  }
  return (right + left) * 0.5;
}
