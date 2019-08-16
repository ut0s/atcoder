/**
  @file c.cpp
  @title C - 幅優先探索
  @url https://atcoder.jp/contests/abc007/tasks/abc007_3
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

int main() {
  int R, C;
  cin >> R >> C;
  int sy, sx, gy, gx;
  cin >> sy >> sx;
  cin >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;

  vector<string> maze;
  string tmp;
  while (cin >> tmp) {
    maze.push_back(tmp);
  }

  int board[R][C];
  REP(i, R) {
    REP(j, C) {
      board[i][j] = -1;
    }
  }

  board[sy][sx] = 0;

  queue<int> queueX;
  queue<int> queueY;
  queueX.push(sx);
  queueY.push(sy);

  vector<pair<int, int>> dir;
  dir.emplace_back(1, 0);
  dir.emplace_back(0, 1);
  dir.emplace_back(-1, 0);
  dir.emplace_back(0, -1);

  int dirs = (int)dir.size();
  while (queueX.size() > 0 && queueY.size() > 0) {
    int x = queueX.front();
    int y = queueY.front();
    queueX.pop();
    queueY.pop();

    for (int i = 0; i < dirs; i++) {
      int nextX = x + dir[i].first;
      int nextY = y + dir[i].second;

      if (0 <= nextX && nextX < C
          && 0 <= nextY && nextY < R
          && board[nextY][nextX] == -1
          && maze[nextY].substr(nextX, 1) == ".") {
        board[nextY][nextX] = board[y][x] + 1;

        if (nextX == gx && nextY == gy) {
          break;
        }

        queueX.push(nextX);
        queueY.push(nextY);
      }
    }
  }

  cout << board[gy][gx] << endl;

  return 0;
}
