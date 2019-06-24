// g++ -std=c++14 -pthread dumptest.cpp

#include<bits/stdc++.h>
#include "dump.hpp"

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
  int in = 0;

  long long l = 0;

  char c = 'a';

  int a[3] = {0, 1, 2};

  char b[3] = {'a', 'b', 'c'};

  pair<int, int> p = make_pair(0, 1);

  tuple<int, double, string> tp = make_tuple(0, 3.14, "Hello");

  string s = "World";

  bitset<8> bs(131ul);

  vector<int> v = {0, 1, 2};

  vector<vector<int>> vv = {{0, 1, 2}, {3, 4}};

  array<int, 2> ar{0, 1};

  valarray<int> va = {3, 4, 5};

  deque<int> deq = {-2, -1, 0, 1, 2};

  list<int> lst(3, 3);

  forward_list<int> flst(4, 4);

  map<int, int> mp;
  rep(i, 5) mp[i] = i;

  multimap<int, int> mmp;
  rep(i, 5) mmp.insert(make_pair(0, i));

  unordered_map<int, int> ump;
  rep(i, 5) ump[i] = i;

  unordered_multimap<int, int> ummp;
  rep(i, 5) ummp.insert(make_pair(0, i));
  
  set<int> st;
  rep(i, 5) st.insert(i);

  multiset<int> mst{3, 1, 4, 1, 5, 9, 2};

  unordered_set<int> ust;
  rep(i, 5) ust.insert(i);

  unordered_multiset<int> umst{3, 1, 4, 1, 5, 9, 2};

  queue<int> q;
  rep(i, 5) q.push(i);

  stack<int> stk;
  rep(i, 5) stk.push(i);

  priority_queue<int, vector<int>, greater<int>> pq;
  rep(i, 5) pq.push(i);

  dump(10, in, l, c, "abc", a, b, p, tp, s, bs, v, vv, va, ar, deq, lst, flst, mp, mmp, ump, ummp, st, mst, ust, umst, q, stk, pq);
  /*
  atomic<int> ai(1);
  dump(ai);
  
  mutex mtx;
  mtx.lock();
  dump(mtx); // locked
  mtx.unlock();
  dump(mtx); // unlocked
  
  recursive_mutex rmtx;
  rmtx.lock();
  dump(rmtx); // locked
  rmtx.unlock();
  dump(rmtx); // unlocked

  timed_mutex tmtx;
  tmtx.lock();
  dump(tmtx); // locked
  tmtx.unlock();
  dump(tmtx); // unlocked
  
  recursive_timed_mutex rtmtx;
  rtmtx.lock();
  dump(rtmtx); // locked
  rtmtx.unlock();
  dump(rtmtx); // unlocked
  */
}
