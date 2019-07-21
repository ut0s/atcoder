/**
  @file c.cpp
  @title D - Megalomania
  @url https://atcoder.jp/contests/abc131/tasks/abc131_d
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()

template <class T>
void show(vector<T>& v) {
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

template <class T1, class T2>
void show(vector<pair<T1, T2>>& v, int x) {
  if (x == 1) {
    for (uint i = 0; i < v.size(); i++) {
      cout << v[i].first << "\t";
    }
  } else if (x == 2) {
    for (uint i = 0; i < v.size(); i++) {
      cout << v[i].second << "\t";
    }
  } else {
    cout << "Wrong Argument";
  }
  cout << "\n";
}

bool compare_by_second(pair<LL, LL> a, pair<LL, LL> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {
  int N;
  cin >> N;
  vector<pair<LL, LL>> AB(N);
  LL tmpA, tmpB;
  for (int i = 0; i < N; i++) {
    cin >> tmpA >> tmpB;
    AB[i] = make_pair(tmpB, tmpA);
  }

  // for debug
  // cout << "Before Sort" << endl;
  // show(AB, 1);
  // show(AB, 2);
  // cout << endl;

  sort(ALL(AB));

  // for debug
  // cout << "After Sort" << endl;
  // show(AB, 1);
  // show(AB, 2);

  LL time = 0;
  for (int i = 0; i < N; i++) {
    time += AB[i].second;
    if (time > AB[i].first) {
      cout << "No" << endl;
      exit(0);
    } else {
      //do nothing
      // cout << i << " "; // for debug
    }
  }
  cout << "Yes" << endl;

  return 0;
}
