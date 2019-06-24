// パターン検索
// mをパターンの長さの和, nを検索テキスト長とすると
// 構築O(m), 検索O(n+m)

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < int(n); i++)
#define all(a) (a).begin(),(a).end()

// pattern matching automaton
struct PMA {
  PMA* next[256];
  vector<int> matched;
  PMA() { memset(next, 0, sizeof(next)); }
  ~PMA() { for(int i = 0; i < 256; i++) if(next[i]) delete next[i]; }
};

vector<int> set_union(const vector<int> &a,const vector<int> &b) {
  vector<int> res;
  set_union(all(a), all(b), back_inserter(res));
  return res;
}

PMA *buildPMA(vector<string> pattern) {
  PMA *root = new PMA, *now;
  root->next[0] = root;
  rep(i,pattern.size()){
    now = root;
    rep(j,pattern[i].size()){
      if(now->next[(int)pattern[i][j]] == 0)
	now->next[(int)pattern[i][j]] = new PMA;
      now = now->next[(int)pattern[i][j]];
    }
    now->matched.push_back(i);
  }

  queue<PMA*> que;
  for(int i = 1; i < 256; i++) {
    if(!root->next[i]) root->next[i] = root;
    else {
      root->next[i]->next[0] = root;
      que.push(root->next[i]);
    }
  }
  while(!que.empty()) {
    now = que.front(); que.pop();
    for(int i = 1; i < 256; i++) {
      if(now->next[i]){
	PMA *nxt = now->next[0];
	while(!nxt->next[i]) nxt = nxt->next[0];
	now->next[i]->next[0] = nxt->next[i];
	now->next[i]->matched = set_union(now->next[i]->matched, nxt->next[i]->matched);
	que.push(now->next[i]);
      }
    }
  }
  return root;
}

void match(PMA* &pma, const string s, vector<int> &res) {
  rep(i,s.size()){
    int c = s[i];
    while(!pma->next[c])
      pma = pma->next[0];
    pma = pma->next[c];
    rep(j,pma->matched.size())
      res[pma->matched[j]] = true;
  }
}

int main(){
  vector<string> ss = {"ab", "abc", "bcd"};
  PMA* pma = buildPMA(ss);
  vector<int> res(ss.size());
  match(pma,"abc",res);
  for(auto i : res) cout << i << endl;
}
