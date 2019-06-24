#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a),i##_cond=(b);i<i##_cond;i++)
using namespace std;

template <class BI>
bool next_partial_permutation(BI first, BI middle, BI last) {
  reverse(middle, last);
  return next_permutation(first, last);
}

int main(void) {
  vector<int> a(5);
  FOR(i, 0, 5) a[i] = i;
  do {
    FOR(i, 0, 3) cout << a[i] << " ";
    cout << endl;
  } while(next_partial_permutation(a.begin(), a.begin() + 3, a.end()));

  return 0;
}
