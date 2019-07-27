/**
  @file c.cpp
  @title C - City Savers
  @url https://atcoder.jp/contests/abc135/tasks/abc135_c
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
  int N;
  cin >> N;

  vector<int> A(N + 1, 0);
  REP(i, N + 1) {
    cin >> A[i];
  }

  vector<int> B(N, 0);
  REP(i, N) {
    cin >> B[i];
  }

  LL ans = 0;
  REP(i, N) {
    if (A[i] > B[i]) {
      ans += B[i];
      A[i] -= B[i];
      B[i] = 0;
    } else if (A[i] == B[i]) {
      ans += B[i];
      A[i] = 0;
      B[i] = 0;
    } else {
      ans += A[i];
      B[i] -= A[i];
      A[i] = 0;

      ans += min(A[i + 1], B[i]);
      A[i + 1] = max(0, A[i + 1] - B[i]);
      B[i] -= min(A[i + 1], B[i]);
    }

    // cout << "Step: " << i << " ans: " << ans << "\n";
    // cout << "A"
    //      << ": ";
    // show(A);
    // cout << "B"
    //      << ": ";
    // show(B);
  }

  cout << ans << endl;
  return 0;
}
