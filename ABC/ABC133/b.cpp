/**
  @file b.cpp
  @title 404 Not Found - AtCoder
  @url https://atcoder.jp/contests/abc133/tasks/abc133_b
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

double distance(vector<int> A, vector<int> B) {
  int sum = 0;
  for (int i = 0; i < A.size(); i++) {
    sum += (A[i] - B[i]) * (A[i] - B[i]);
  }
  return sqrt(sum);
}

int main() {
  int i, j;

  int N, D;
  cin >> N >> D;

  vector<vector<int>> X(N, vector<int>(D, 0));
  REP(i, N)
  REP(j, D)
  cin >> X[i][j];

  int count = 0;
  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      double dis = distance(X[i], X[j]);
      if (ceil(dis) == floor(dis)) count++;
    }
  }

  cout << count << endl;

  return 0;
}
