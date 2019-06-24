#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()

using vd = vector<double>;
using vvd = vector<vd>;

// イベント追加
void add(vvd &sections, const vd &e){
  sections.push_back({e[2],0}); // 始点イベント
  sections.push_back({e[3],1}); // 終点イベント
}

// イベント削除
void del(vvd &sections, const vd &e){
  // 始点イベントを削除
  vd tmp = {e[2],0};
  auto itr = find(all(sections),tmp);
  sections.erase(itr);
  // 終点イベントを削除
  tmp = {e[3],1};
  itr = find(all(sections),tmp);
  sections.erase(itr);
}

// 区間の和集合の大きさ
double sum(vvd &sections){
  double res = 0;
  sort(all(sections));
  double l = sections[0][0]; // 区間の左端
  int cnt = 1; // いくつの区間が重なっているか
  FOR(i,1,sections.size())
    if(sections[i][1] == 0){
      cnt++;
      if(cnt == 1) l = sections[i][0]; // 1つ目なら左端を更新
    }else{
      cnt--;
      if(cnt == 0) res += sections[i][0] - l; // 閉じたら右端-左端を足す
    }

  return res;
}

signed main(){
  int n, cnt = 1;
  while(cin >> n, n){
    vvd es;
    rep(i,n){
      double x,y,r;
      cin >> x >> y >> r;
      es.push_back({x-r,0,y-r,y+r}); // 追加イベント
      es.push_back({x+r,1,y-r,y+r}); // 削除イベント
    }
    sort(all(es));

    double ans = 0;
    vvd sections;
    add(sections, es[0]);
    FOR(i,1,es.size()){
      if(es[i][0] != es[i-1][0])
	ans += (es[i][0] - es[i-1][0]) * sum(sections);

      if(es[i][1] == 0)
	add(sections,es[i]);
      else
	del(sections,es[i]);
    }
    printf("%d %.2lf\n",cnt,ans);
    cnt++;
  }
}
