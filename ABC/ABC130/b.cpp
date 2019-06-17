/**
  @file b.cpp
  @title B - Bounding
  @brief https://atcoder.jp/contests/abc130/tasks/abc130_b
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
  int i;
  int N, X;
  cin >> N >> X;

  vector<int> L(N, 0);
  for (i = 0; i < N; i++) {
    cin >> L[i];
  }
  // show(L);

  int D     = 0;
  int count = 0;
  for (i = 0; i < N; i++) {
    if (D <= X) {
      count++;
    }
    D = D + L[i];
  }

  cout << count << endl;

  return 0;
}
