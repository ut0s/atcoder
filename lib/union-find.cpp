/**
  @date Time-stamp: <2019-07-15 07:44:39 tagashira>
  @file union-find.cpp
  @brief Union-Find Tree inplementation
**/

#include <iostream>
#include <vector>

template <class T>
class UnionFind {
public:
  std::vector<T> par;
  std::vector<T> rank;

  UnionFind(T N)
    : par(N, 0), rank(N, 0) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
      // rank[i] = 0;
    }
  };

  T root(T x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]); // path compression
    }
  }

  bool same(T x, T y) {
    return (root(x) == root(y));
  }

  void unite(T x, T y) {
    T rx = root(x);
    T ry = root(y);
    if (rx == ry) return;

    if (rank[rx] < rank[ry]) {
      par[rx] = ry;
    } else {
      par[ry] = rx;
      if (rank[rx] == rank[ry]) rank[rx]++;
    }
  }

  void show() {
    std::cout << "index:\t";
    for (uint i = 0; i < par.size(); i++) {
      std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "par:\t";
    for (uint i = 0; i < par.size(); i++) {
      std::cout << par[i] << " ";
    }
    std::cout << "\n";
  }
};
