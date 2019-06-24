#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

int main(){
#define int ll
  while(1){
    int n; cin >> n; if(n == 0) break;
    
    int m; cin >> m;
    vector<vector<pii>> origin(8,vector<pii>(m));
    rep(i,m){
      cin >> origin[0][i].fst >> origin[0][i].snd;
    }
    rep(i,m-1){
      origin[0][i+1].fst -= origin[0][0].fst;
      origin[0][i+1].snd -= origin[0][0].snd;
    }
    vector<function<pii(pii)>> f(3);
    f[0] = [](pii p){ return pii(-p.snd, p.fst); };
    f[1] = [](pii p){ return pii(-p.fst, -p.snd); };
    f[2] = [](pii p){ return pii(p.snd, -p.fst); };
    rep(i,3) rep(j,m){
      origin[i+1][j] = f[i](origin[0][j]);
    }

    rep(i,n){
      int l; cin >> l;
      vector<pii> tmp1(l), tmp2(l);
      rep(j,l){
	cin >> tmp1[j].fst >> tmp1[j].snd;
	tmp2[l-1-j] = tmp1[j];
      }
      if(l != m) continue;
      rep(j,l-1){
	tmp1[j+1].fst -= tmp1[0].fst;
	tmp1[j+1].snd -= tmp1[0].snd;
	tmp2[j+1].fst -= tmp2[0].fst;
	tmp2[j+1].snd -= tmp2[0].snd;
      }
      bool flag1 = false;
      rep(j,4){
	bool flag2 = true;
	rep(k,l-1)
	  if(tmp1[k+1].fst != origin[j][k+1].fst or tmp1[k+1].snd != origin[j][k+1].snd) flag2 = false;
	if(flag2){
	  flag1 = true;
	  //cout << "1 " << j << endl;
	}
      }
      rep(j,4){
	bool flag2 = true;
	rep(k,l-1)
	  if(tmp2[k+1].fst != origin[j][k+1].fst or tmp2[k+1].snd != origin[j][k+1].snd) flag2 = false;
	if(flag2){
	  flag1 = true;
	  //cout << "2 " << j << endl;
	}
      }
      if(flag1) cout << i + 1 << endl;
    }
    cout << "+++++" << endl;
  }
}
