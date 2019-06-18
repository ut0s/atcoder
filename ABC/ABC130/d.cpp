/**
  @file d.cpp
  @title D - Enough Array
  @brief https://atcoder.jp/contests/abc130/tasks/abc130_d
**/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

int main(int argc, char* argv[]) {
  long long N, K;
  cin >> N >> K;

  vector<long long> a(N, 0);
  vector<long long> S(N + 1, 0);
  for (long long i = 0; i < N; i++) {
    cin >> a[i];
    S[i + 1] = S[i] + a[i];
  }
  // show(S);

  long long ans = 0;
  for (long long end = N; S[end] >= K && end >= 0; end--) {
    for (long long start = end; start >= 0; start--) {
      if (S[end] - S[start] >= K) {
        ans += start - 0 + 1;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
