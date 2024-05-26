#!/usr/bin/env python3
# @url https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_c

import random
import time
import logging
from sys import stdin
logging.basicConfig(level=logging.DEBUG,
                    format="%(funcName)s:\t%(message)s")


def get_input():
  # input = stdin.readline
  D = int(input())
  C = list(map(int, input().split()))
  S = [list(map(int, input().split())) for _ in range(D)]

  # debug print
  logging.debug('C = {}'.format(C))
  logging.debug('S = [')
  for s in S:
    logging.debug('{}'.format(s))
  logging.debug(']')
  return (D, C, S)


def calc_score(D, C, S, T):
  score = 0
  last_di = [0 for _ in range(len(C))]
  for day in range(D):
    contest = T[day]-1
    last_di[contest] = day+1
    score += S[day][contest]
    for type_i in range(26):
      score -= C[type_i] * (day+1 - last_di[type_i])
  return score


def get_greedy(D, S):
  ans = []
  for day in range(D):
    contest = S[day].index(max(S[day]))+1
    ans.append(contest)
  logging.debug('greedy: {}'.format(ans))
  return ans


def evaluate(D, C, S):
  ans = get_greedy(D, S)
  time_start = time.perf_counter()
  time_end = time_start
  prev_score = calc_score(D, C, S, ans)
  logging.debug('initial score: {}'.format(prev_score))
  while time_end - time_start < 1.93:
    tmp = ans.copy()
    tmp_day = random.randint(0, D-1)
    tmp_type = random.randint(1, 26)
    tmp[tmp_day] = tmp_type
    tmp_score = calc_score(D, C, S, tmp)
    if tmp_score > prev_score:
      logging.debug(
          'score: {} > prev_score: {}\ttmp: {}'.format(tmp_score, prev_score, tmp))
      # save current state
      prev_score = tmp_score
      ans = tmp.copy()
    time_end = time.perf_counter()
  logging.debug('last score: {}\tlast ans: {}'.format(
      prev_score, ans))
  return ans


def main():
  D, C, S = get_input()
  ans = evaluate(D, C, S)
  for a in ans:
    print(a)


if __name__ == "__main__":
  main()
