/**
  @date Time-stamp: <2019-04-06 21:19:01 tagashira>
  @file a.cpp
  @brief https://atcoder.jp/contests/abc123/tasks/abc123_a
**/

#include <iostream>
#include <string>

using namespace std;

bool can_comm(string a, string b, string k) {
  int A = stoi(a);
  int B = stoi(b);
  int K = stoi(k);

  if (abs(A - B) <= K) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char* argv[]) {
  string a;
  cin >> a;
  string b;
  cin >> b;
  string c;
  cin >> c;
  string d;
  cin >> d;
  string e;
  cin >> e;
  string k;
  cin >> k;

  if (can_comm(a, b, k) &&
      can_comm(a, c, k) &&
      can_comm(a, d, k) &&
      can_comm(a, e, k) &&
      can_comm(b, c, k) &&
      can_comm(b, d, k) &&
      can_comm(b, e, k) &&
      can_comm(c, d, k) &&
      can_comm(c, e, k) &&
      can_comm(d, e, k)
      ) {
    cout << "Yay!"         << "\n";
  } else {
    cout << ":("         << "\n";
  }

  return 0;
}
