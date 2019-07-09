/**
  @file c.cpp
  @title 404 Not Found - AtCoder
  @url https://atcoder.jp/contests/abc133/tasks/abc133_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main() {
  int i, j;

  int L, R;
  cin >> L >> R;

  const int mod = 2019;

  if (R - L >= 2019) {
    cout << "0" << endl;
    return 0;
  }

  vector<int> ans;
  for (i = L % mod; i < R % mod; i++) {
    for (j = i + 1; j <= R % mod; j++) {
      ans.push_back((i * j) % mod);
    }
  }

  sort(ALL(ans));
  // show(ans);
  cout << ans[0] << endl;

  return 0;
}
