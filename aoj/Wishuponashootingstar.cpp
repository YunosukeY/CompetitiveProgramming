#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;++i)
#define all(a) (a).begin(),(a).end()
using pii = pair<int,int>;
constexpr double EPS = 1e-8;
constexpr double INF = 1e8;
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

int main(){
  int n;
  while(cin >> n, n){
    vector<vector<double>> data(n,vector<double>(8));
    rep(i,n) rep(j,8) cin >> data[i][j];

    vector<pair<double,pair<int,int>>> can;
    // 消滅
    rep(i,n)
      can.emplace_back(data[i][6]/data[i][7], pii(i,-1));
    // 衝突
    rep(i,n) FOR(j,i+1,n){
      // 2次方程式の係数を計算
      double a = 0, b = 0, c = 0;
      rep(k,3){
	a += pow(data[i][3+k]-data[j][3+k],2);
	b += 2 * (data[i][k]-data[j][k]) * (data[i][3+k]-data[j][3+k]);
	c += pow(data[i][k]-data[j][k],2);
      }
      a -= pow(data[i][7]+data[j][7],2);
      b -= -2 * (data[i][6]+data[j][6]) * (data[i][7]+data[j][7]);
      c -= pow(data[i][6]+data[j][6],2);
      // 解を候補に追加
      double D = pow(b,2) - 4 * a * c;
      if(D - EPS > 0){
	vector<double> sol{(-b-sqrt(D)) / (2*a), (-b+sqrt(D)) / (2*a)};
	rep(k,2){
	  if(sol[k] - EPS > 0){ // EPSの符号に注意（問題より0に近いところでは衝突しない）
	    can.emplace_back(sol[k], pii(i,j));
	    break;
	  }
	}
      }
    }
    
    sort(all(can));
    vector<double> time(n,INF);
    rep(i,can.size()){
      double t = can[i].first;
      int a = can[i].second.first, b = can[i].second.second;
      if(b == -1 and time[a] == INF){
    	time[a] = t;
      }else if(time[a] == INF and time[b] == INF){
    	time[a] = t;
    	time[b] = t;
      }
    }
    rep(i,n)
      printf("%.10lf\n",time[i]);
  }
}
