#!/usr/bin/env python3
# @url https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_b

import random
import logging
from sys import stdin
logging.basicConfig(level=logging.DEBUG,
                    format="%(funcName)s:\t%(message)s")


def get_input():
  # input = stdin.readline
  D = int(input())
  C = list(map(int, input().split()))
  S = [list(map(int, input().split())) for _ in range(D)]
  T = [int(input()) for _ in range(D)]

  # debug print
  logging.debug('C = {}'.format(C))
  logging.debug('S = [')
  for s in S:
    logging.debug('{}'.format(s))
  logging.debug(']')
  logging.debug('T = {}'.format(T))
  return (D, C, S, T)


def score(D, C, S, T):
  score = 0
  satisfaction = []
  last_di = [0 for _ in range(len(C))]
  for day in range(D):
    contest = T[day]-1
    last_di[contest] = day+1
    score += S[day][contest]
    logging.info('day={}, contest={}'.format(day, contest))
    for type_i in range(26):
      score -= C[type_i] * (day+1 - last_di[type_i])
    satisfaction.append(score)
    logging.info('d={} : {}'.format(day, satisfaction))
  return satisfaction


def main():
  D, C, S, T = get_input()
  satisfaction = score(D, C, S, T)
  for s in satisfaction:
    print(s)


if __name__ == "__main__":
  main()
