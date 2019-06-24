#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int MAXN = 1000100;
vector<int> G[MAXN];
ull dp[MAXN];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  ull K;
  cin >> s;
  cin >> K;
  vector<int> edge(26, -1);
  int N = s.size();
  for (int i = N; i > 0; i--) {
    G[i] = edge;
    edge[s[i-1]-'a'] = i;
  }
  G[0] = edge;
  for (int i = N; i >= 0; i--) {
    dp[i] = (i>0);
    for (int j = 0; j < 26; j++) {
      int to = G[i][j];
      if (to != -1) {
	dp[i] += dp[to];
	if (dp[i] > K) dp[i] = K+1;
      }
    }
  }
  if (dp[0] < K) cout << "Eel" << endl;
  else {
    string ans;
    int now = 0;
    ull k = 0;
    while (k < K) {
      for (int j = 0; j < 26; j++) {
	int to = G[now][j];
	if (to == -1) continue;
	if (k+dp[to] < K) {
	  k += dp[to];
	} else {
	  k++;
	  now = to;
	  ans += (char)('a'+j);
	  break;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
