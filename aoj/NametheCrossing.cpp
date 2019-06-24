#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,n) for(ll i = 0; i < ll(n); ++i) 
#define FOR(i,a,b) for(ll i = (a); i < ll(b); ++i) 
#define ROF(i,a,b) for(ll i = (a)-1; i >= ll(b); --i) 
#define all(a) (a).begin(),(a).end() 
#define fst first 
#define snd second 
typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
const ll inf = 1ll<<10;

bool dfs(const vii &g, ll i, vi &color){
  ll sz = g.size();
  stack<ll> st;
  color[i] = 1;
  st.push(i);

  while(!st.empty()){
    int now = st.top();
    st.pop();

    rep(next,sz){
      if(now == next) continue;
      if(g[now][next] + g[next][now] == 0){ // now<->next
	if(color[next] and color[next] != color[now]){
	  //cout << now << endl << next << endl;
	  return false; 
	}else if(color[next] and color[next] == color[now]) continue;
	else{
	  color[next] = color[now];
	  st.push(next);
	}
      }else if(g[now][next] * g[next][now] == 0){ // now->next or next->now
	if(color[next] and color[next] == color[now]){
	  //cout << now << endl << next << endl;
	  return false;
	}else if(color[next] and color[next] != color[now]) continue;
	else{
	  color[next] = -color[now];
	  st.push(next);
	}
      }
    }
  }
  return true;
}

bool paintable(const vii &g, vi &color){
  ll sz = g.size();
  rep(i,sz) if(color[i] == 0) if(dfs(g,i,color) == false) return false;
  return true;
}

main(){
  ll m,n; 
  while(cin >> m, m){ 
    vector<string> input(m); 
    vector<vector<string>> cross(m,vector<string>(2)); 
    set<string> street; 
    rep(i,m){ 
      cin >> input[i]; 
      FOR(k,1,input[i].size()){ // A-BをAとBに分ける 
	if(input[i][k] == '-'){ 
	  cross[i][0] = input[i].substr(0,k); 
	  cross[i][1] = input[i].substr(k+1,input[i].size()-k-1); 
	  street.insert(cross[i][0]); 
	  street.insert(cross[i][1]); 
	  //cerr << cross[i][0] << endl << cross[i][1] << endl; 
	  break; 
	} 
      } 
    } 
    map<string,ll> ntoi; // 通りの名前からindex
    vector<string> iton; // indexから通りの名前
    ll tmpi = 0;
    for(auto name : street){ 
      ntoi[name] = tmpi;
      iton.push_back(name);
      tmpi++;
    }
    ll sz = street.size(); cout << sz << endl;
    vii g(sz,vi(sz,1)); 
    rep(i,m) g[ ntoi[cross[i][0]] ][ ntoi[cross[i][1]] ] = 0; // A->B
    
    vector<pair<ll,ll>> eqp; // 同水準のpair
    rep(i,sz) rep(j,sz){ // iとjが同水準か
      bool ieqj = false;
      rep(k,sz){
	if((g[i][k] + g[k][j]) * (g[j][k] + g[k][i]) == 0){ // i->k->jかj->k->iがある
	  ieqj = false;
	  break;
	}else if((g[i][k] + g[j][k]) * (g[k][i] + g[k][j]) == 0){ // i->k,j->kかk->i,k->jがある
	  ieqj = true;
	}
      }
      if(ieqj) eqp.push_back(make_pair(i,j));
    }
    rep(i,eqp.size()) g[eqp[i].fst][eqp[i].snd] = g[eqp[i].snd][eqp[i].fst] = 0; // A<->B
    //rep(i,sz){ rep(j,sz) cout << g[i][j] << " "; cout << endl; }

    vii d = g; // path i->j がある <=> d[i][j] == 0
    rep(k,sz) rep(i,sz) rep(j,sz) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    vi color(sz);
    bool p = paintable(g,color);
    //cout << "p : " << p << endl;
    //rep(i,sz) cout << iton[i] << " : " << color[i] << endl;

    cin >> n;
    rep(k,n){
      string q; cin >> q;
      if(p == false){
	cout << "NO\n";
	continue;
      }
      string ql, qr;
      FOR(i,1,q.size()){ // A-BをAとBに分ける 
	if(q[i] == '-'){ 
	  ql = q.substr(0,i); 
	  qr = q.substr(i+1,q.size()-i-1);
	  break; 
	} 
      }
      if(ntoi.count(ql) * ntoi.count(qr) == 0){
	cout << "NO\n";
	continue;
      }
      if(d[ntoi[ql]][ntoi[qr]] != 0){
	cout << "NO\n";
	continue;
      }
      //cout << color[ntoi[ql]] << endl << color[ntoi[qr]] << endl;
      if(color[ntoi[ql]] != color[ntoi[qr]]) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}
