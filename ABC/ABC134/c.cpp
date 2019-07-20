/**
  @file c.cpp
  @title C - Exception Handling
  @url https://atcoder.jp/contests/abc134/tasks/abc134_c
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;

  vector<int> A(N, 0);
  vector<int> sorted(N, 0);
  REP(i, N) {
    cin >> A[i];
    sorted[i] = A[i];
  }

  sort(ALL(sorted), std::greater<int>());

  REP(i, N) {
    if (A[i] == sorted[0]) {
      cout << sorted[1] << "\n";
    } else {
      cout << sorted[0] << "\n";
    }
  }

  return 0;
}
