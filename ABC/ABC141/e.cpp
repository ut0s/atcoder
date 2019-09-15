/**
  @file e.cpp
  @title E - Who Says a Pun?
  @url https://atcoder.jp/contests/abc141/tasks/abc141_e
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  string tmp = S;
  sort(ALL(tmp));
  tmp.erase(unique(ALL(tmp)), tmp.end());
  // cout << tmp << "\n";

  int len = 1;
  if ((int)tmp.size() == N) {
    len = 0;
  } else {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        while (S.substr(i, len) == S.substr(j, len) && S.substr(i, len + 1) == S.substr(j, len + 1) && i + len < j) {
          len++;
        }
      }
    }
  }

  cout << len << endl;
  return 0;
}
