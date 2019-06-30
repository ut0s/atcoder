/**
  @file a.cpp
  @title A - Fifty-Fifty
  @url https://atcoder.jp/contests/abc132/tasks/abc132_a
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  string S;
  cin >> S;

  vector<int> memo(4, 0);
  for (int i = 0; i < S.length(); i++) {
    for (int j = 0; j < S.length(); j++) {
      if (S[j] == S[i]) {
        memo[j]++;
      }
    }
  }

  if ((*max_element(ALL(memo)) == 2) && (*min_element(ALL(memo)) == 2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
