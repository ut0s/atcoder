/**
  @file e.cpp
  @title E - 1 or 2
  @url https://atcoder.jp/contests/abc126/tasks/abc126_e
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

template <class T>
class UnionFind {
public:
  std::vector<T> par;
  std::vector<T> rank;

  UnionFind(T N)
    : par(N, 0), rank(N, 0) {
    for (T i = 0; i < N; i++) {
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

  bool same(T x, T y) { return (root(x) == root(y)); }

  void unite(T x, T y) {
    T rx = root(x);
    T ry = root(y);
    if (rx == ry)
      return;

    if (rank[rx] < rank[ry]) {
      par[rx] = ry;
    } else {
      par[ry] = rx;
      if (rank[rx] == rank[ry])
        rank[rx]++;
    }
  }

  void show() {
    cout << "index:\t";
    for (uint i = 0; i < par.size(); i++) {
      cout << i << " ";
    }
    cout << "\n";

    cout << "par:\t";
    for (uint i = 0; i < par.size(); i++) {
      cout << par[i] << " ";
    }
    cout << "\n";
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> X(M, 0);
  vector<int> Y(M, 0);
  vector<int> Z(M, 0);

  REP(i, M) {
    cin >> X[i] >> Y[i] >> Z[i];
  }

  UnionFind<int> uf(N);

  // REP(i, M) {
  //   if ((Z[i] % 2) == 0) {
  //     uf.unite(X[i], Y[i]);
  //   } else {
  //     uf.unite(X[i], Y[i]);
  //   }
  // }
  REP(i, M) {
    uf.unite(X[i]-1, Y[i]-1);
  }

  int ans = 0;
  REP(i, N) {
    if (uf.root(i) == i) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
