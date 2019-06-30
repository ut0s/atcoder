/**
  @file utils.cpp
  @brief utils
**/

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
