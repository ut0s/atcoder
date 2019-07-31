/**
  @file d.cpp
  @title D - Handstand
  @url https://atcoder.jp/contests/abc124/tasks/abc124_d
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int i;

  int N, K;
  cin >> N >> K;

  string S;
  cin >> S;

  vector<int> data;
  // 先頭が 0 だったら
  if (S[0] == '0') {
    data.push_back(0);
  }

  // S[i] の数値がどこまで続くか
  for (i = 0; i < (int)S.size();) {
    int j = i;
    while (j < (int)S.size() && S[i] == S[j]) {
      j++;
    }
    data.push_back(j - i);
    i = j;
  }

  // 最後尾が 0 だったら
  if (S.back() == '0') {
    data.push_back(0);
  }

  vector<int> sums((int)data.size() + 1, 0);
  REP(i, (int)data.size()) {
    sums[i + 1] = sums[i] + data[i];
  }

  int res = 0;
  for (int left = 0; left < (int)data.size(); left += 2) {
    int right = left + K * 2 + 1;
    if (right >= (int)sums.size()) {
      right = (int)sums.size() - 1;
    }
    res = max(res, sums[right] - sums[left]);
  }

  cout << res << endl;
  return 0;
  }
