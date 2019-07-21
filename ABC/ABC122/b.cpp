/**
  @date Time-stamp: <2019-05-14 22:43:39 tagashira>
  @file b.cpp
  @title B - ATCoder
  @url https://atcoder.jp/contests/abc122/tasks/abc122_b
**/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream> // std::ostringstream
#include <string>
#include <vector>

using namespace std;

vector<string> split(string& str, char sep) {
  vector<string> v;
  stringstream ss(str);
  string buffer;
  while (std::getline(ss, buffer, sep)) {
    v.push_back(buffer);
  }
  return v;
}

int main(int argc, char* argv[]) {
  string S;
  cin >> S;

  string tmp = "";
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == 'A' || S[i] == 'G' || S[i] == 'C' || S[i] == 'T') {
      tmp += "1";
    } else {
      tmp += "0";
    }
  }
  // cout << tmp << "\n"; //for debug

  string for_split = "";
  vector<int> res;

  for (int i = 0; i < tmp.length(); i++) {
    if (tmp[i] == '1') {
      for_split += "1";
    } else {
      for_split += ":";
    }
  }
  // cout << for_split << "\n"; //for debug

  vector<string> splited = split(for_split, ':');

  for (int i = 0; i < splited.size(); i++) {
    // cout << splited[i].size() << "\n"; //for debug
    res.push_back(splited[i].size());
  }

  cout << *max_element(res.begin(),res.end()) << "\n";

  return 0;
}
