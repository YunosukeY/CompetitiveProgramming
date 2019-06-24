#include<bits/stdc++.h>

#ifdef LOCAL
#include "../dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define pb push_back
#define fst first
#define snd second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

#define MAX 100000

struct union_find {
    int rnk[MAX], par[MAX];

    union_find(int n) { for(int i = 0; i < n; i++) rnk[i] = 1, par[i] = i; }

    int find(int x) {
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rnk[x] > rnk[y]) par[y] = x;
        else{
            par[x] = y;
            if(rnk[x] == rnk[y]) rnk[y]++;
        }
    }
    bool same(int x, int y) {
        x = find(x); y = find(y);
        return x == y;
    }
};

struct edge {
    int from, to, cst;
    edge(){}
    edge(int from, int to, int cst) : from(from), to(to), cst(cst) {}
    bool operator<(const edge &e) const { return cst < e.cst; }
};

int n;

// Eが連結ならTに最小全域木が入る
int kruskal(vector<edge> &E, vector<edge> &T) {
    sort(E.begin(), E.end());
    T.clear();
    union_find uf(n) ;
    int w = 0;
    for(int i = 0; i < E.size(); i++){
        edge &e = E[i];
        if(uf.same(e.from, e.to)) continue;
        uf.unite(e.from, e.to);
        w += e.cst;
        T.push_back(e);
    }
    return w;
}

int main(){
  cin >> n;
  vector<pii> x(n),y(n);
  rep(i,n){
    cin >> x[i].fst >> y[i].fst;
    x[i].snd = y[i].snd = i;
  }
  
  sort(all(x)); sort(all(y));
  vector<edge> e,t;
  rep(i,n-1){
    e.pb((edge){x[i].snd,x[i+1].snd,abs(x[i].fst-x[i+1].fst)});
    e.pb((edge){y[i].snd,y[i+1].snd,abs(y[i].fst-y[i+1].fst)});
  }
  cout << kruskal(e,t) << endl;
}
