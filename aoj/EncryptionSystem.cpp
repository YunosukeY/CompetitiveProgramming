#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,i##_cond=(n);i<i##_cond;++i)
using vi = vector<int>;

signed main(){
  string s;
  while(cin >> s, s != "#"){
    int l = s.size();
    set<string> st;
    rep(i,1<<l){ // bitが立っているところをずらす
      string t = s;
      rep(j,l){ // j文字目
	if((i>>j)&1 and t[j] < 'z') t[j]++;
      }
      string u = t;

      // ルールを適用してsになるか試す
      vi num('z'-'a'+1); // 左から見ていくつ目か
      rep(j,l){
	if('a' < t[j] and num[t[j]-'a'] == 0){
	  num[t[j]-'a'] = 1;
	  t[j]--;
	}
	if(s[j] != t[j]) break;
      }
      st.insert(u);
    }

    cout << st.size() << endl;
    if(st.size() < 10){
      for(auto t : st) cout << t << endl;
    }else{
      int i = 0;
      auto itrr = st.end();
      for(auto itrl = st.begin(); i < 5; --itrr,++itrl,i++)
	cout << *itrl << endl;
      for(i = 0; i < 5; ++itrr,i++)
	cout << *itrr << endl;
    }
  }
}
