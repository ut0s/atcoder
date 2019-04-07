 /**
  @date Time-stamp: <2019-04-06 22:00:56 tagashira>
  @file a.cpp
  @brief https://atcoder.jp/contests/abc123/tasks/abc123_b
**/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

  using namespace std;

int count_ten(int n) {
  int org_num = n;
  int count   = 0;
  while (org_num > 0) {
    count++;
    org_num -= 10;
  }
  return count;
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

  vector<string> abcde;
  abcde.push_back(a);
  abcde.push_back(b);
  abcde.push_back(c);
  abcde.push_back(d);
  abcde.push_back(e);

  vector<int> last(abcde.size(), 0);
  int sum = 0;

  // test count_ten
  // cout << count_ten(20) << endl;
  // cout << count_ten(29) << endl;

  for (int i = 0; i < abcde.size(); i++) {
    int tmp = stoi(abcde[i].substr(abcde[i].length() - 1));
    sum += count_ten(stoi(abcde[i]));
    if (tmp == 0) {
      last[i] = 10;
    } else {
      last[i] = tmp;
    }
    // cout << last[i] << "\n";
  }

  int min = *min_element(last.begin(), last.end());

  cout << sum * 10 - (10 -min ) << "\n";

  return 0;
}
