#!/bin/bash
# @date Time-stamp: <2019-09-01 21:02:56 tagashira>
# @file act.sh
# @brief wrapper script of online-judge-tools

set -ue

readonly open_browser="google-chrome"
readonly path_to_atcoder="$HOME/atcoder/"

function usage() {
  cat <<EOS
Usage:
  $0 COMMAND

  COMMAND      update, login, session, logout, new, dl, test, sys|system, sub|submit, open, me, help
EOS
  echo ""
  cat ${path_to_atcoder}/bin/act.sh | grep "@doc" |cut -d ' ' -f2- |tail -n +2

  exit 0
}


check_oj(){
  which oj > /dev/null || ./install-oj.sh
}


# @doc update update problem json
update_problem_json(){
  now=$(date +%s)
  if [ -e ${path_to_atcoder}/etc/.problems.json ]
  then
    modify=$(date +%s -r ${path_to_atcoder}/etc/.problems.json)

    if [ $(($now - $modify)) -gt $((1*60*60)) ]
    then
      ping -c 1 google.com > /dev/null && curl -s 'https://kenkoooo.com/atcoder/resources/problems.json' -H 'authority: kenkoooo.com' -H 'cache-control: max-age=0' -H 'upgrade-insecure-requests: 1' -H 'user-agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36' -H 'dnt: 1' -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3' -H 'referer: https://github.com/kenkoooo/AtCoderProblems' -H 'accept-encoding: gzip, deflate, br' -H 'accept-language: ja-JP,ja;q=0.9,en-US;q=0.8,en;q=0.7' --compressed > ${path_to_atcoder}/etc/.problems.json && echo "Update"
    fi
  else
    ping -c 1 google.com > /dev/null && curl -s 'https://kenkoooo.com/atcoder/resources/problems.json' -H 'authority: kenkoooo.com' -H 'cache-control: max-age=0' -H 'upgrade-insecure-requests: 1' -H 'user-agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36' -H 'dnt: 1' -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3' -H 'referer: https://github.com/kenkoooo/AtCoderProblems' -H 'accept-encoding: gzip, deflate, br' -H 'accept-language: ja-JP,ja;q=0.9,en-US;q=0.8,en;q=0.7' --compressed > ${path_to_atcoder}/etc/.problems.json && echo "Init Download"
  fi
}


# @doc login AtCoder
oj_login(){
  local USER
  local PASSWORD

  echo -n "Username: "
  read USER
  echo -n "Password: "
  read -s PASSWORD

  oj login -u ${USER} -p ${PASSWORD} https://atcoder.jp
}


# @doc session check  AtCoder login session
oj_session(){
  oj login --check https://atcoder.jp
}

# @doc logout from AtCoder
oj_logout(){
  local path_to_cookie
  path_to_cookie=$(oj_session 2>&1 | grep "save cookie" |cut -d ' ' -f 5) #$HOME/.local/share/online-judge-tools/cookie.jar

  read -p "Are you sure to logout ? [Y/n] " -n 1 -r
  echo ""   # (optional) move to a new line
  if [[ $REPLY =~ ^[Y]$ ]]
  then
    rm -f $path_to_cookie
  fi
}

# @doc new <contest_id> make new folder, touch file(*.cpp), insert template, and move
oj_new(){
  local contest_id=$2

  update_problem_json

  cat ${path_to_atcoder}/etc/.problems.json |jq -r '.[].contest_id' |sort -d |uniq | grep $contest_id > /dev/null && FLAG_EXIST=1  || FLAG_EXIST=0

  if [ ${FLAG_EXIST} -eq "1" ]
  then
    echo "contest exists"
    local contest=$(echo $contest_id | tr -cd '[a-z]\n')

    case "$contest" in
      "abc" ) echo "AtCoder Beginner Contest" && setup_normal_contest $contest_id ;;
      "arc" ) echo "AtCoder Regular Contest" && setup_normal_contest $contest_id ;;
      "agc" ) echo "AtCoder Grand Contest" && setup_normal_contest $contest_id ;;
      * ) echo "special contest\nPlease setup on your own." ;;
    esac
  else
    echo "contest_id is wrong."
    echo "Enter manual setup ..."
    setup_manual $contest_id
  fi

  echo $(pwd)
}

setup_normal_contest(){
  cd $path_to_atcoder # $HOME/atcoder

  local contest_id=$1
  local contest=$(echo $contest_id | tr -cd '[a-z]\n')
  local contest_num=$(echo $contest_id | tr -cd '0123456789\n')

  mkdir -p ${contest^^}/${contest^^}${contest_num}
  cd ${contest^^}/${contest^^}${contest_num}
  ln -fs ${path_to_atcoder}/etc/Makefile .

  for id in $(cat ${path_to_atcoder}/etc/.problems.json |jq -r '.[].id' |grep $contest_id ); do
    level=$(echo $id |cut -d '_' -f2) # ex.) a,b,c,d
    title=$(cat ${path_to_atcoder}/etc/.problems.json |jq -r ".[] | select(.id==\"$id\") | .title" | sed 's#\.# -#')

    url="https://atcoder.jp/contests/${contest}${contest_num}/tasks/${id}"

    if [ -e $level.cpp ]
    then
      oj_download $level $url
    else
      touch $level.cpp
      cat <<EOS >> $level.cpp
/**
  @file $level.cpp
  @title $title
  @url $url
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)


int main() {
  int i, j, k, l;

  string S;
  cin >> S;

  int N;
  cin >> N;

  cout << "" << endl;
  return 0;
}

EOS

      oj_download $level $url
    fi
  done
}


setup_manual(){
  echo "Warning: this is manual setup process"
  cd $path_to_atcoder # $HOME/atcoder

  local contest_id=$1
  local contest=$(echo $contest_id | tr -cd '[a-z]\n')
  local contest_num=$(echo $contest_id | tr -cd '0123456789\n')

  mkdir -p ${contest^^}/${contest^^}${contest_num}
  cd ${contest^^}/${contest^^}${contest_num}
  ln -fs ${path_to_atcoder}/etc/Makefile .

  for level in {a..f}; do # ex.) a,b,c,d
    url="https://atcoder.jp/contests/${contest}${contest_num}/tasks/${contest_id}_${level}"
    title=""

    if [ -e $level.cpp ]
    then
      oj_download $level $url
    else
      touch $level.cpp
      cat <<EOS >> $level.cpp
/**
  @file $level.cpp
  @title $title
  @url $url
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)


int main() {
  int i, j, k, l;

  string S;
  cin >> S;

  int N;
  cin >> N;


  cout << "" << endl;
  return 0;
}

EOS

      oj_download $level $url
    fi
  done
}


# @doc dl <level> <url> download testcase
oj_download(){
  local level=$1
  local url=$2

  mkdir -p test
  oj download --silent -d test/$level $url
}

# @doc dlsys <contest id> download system testcase
oj_download_sys(){
  local command=$1
  local contest_id=$2

  $path_to_atcoder/bin/dl_system_testcase.sh $contest_id
}


# @doc test <level> test sample case
oj_test(){
  local command=$1
  local level=$2

  make $level
  oj test --print-input --print-memory -d test/$level -c ./$level
}

# @doc sys|system <level> test all testcase
oj_system_test(){
  local command=$1
  local level=$2

  make $level
  if [ ! -d system/$level ]; then oj_download_sys temp $(cat $level.cpp | grep "@url" | cut -d '/' -f5) ;fi
  oj test --print-input --print-memory -d system/$level -c ./$level
}


# @doc sub|submit <level> test sample case
oj_submit(){
  local command=$1
  local level=$2

  local url=$(cat $level.cpp | grep "@url" | cut -d ' ' -f4)

  oj submit --language 3003 --no-guess --wait 0 --guess-cxx-compiler gcc --no-open $url $level.cpp |& tee tmp.log
  readonly submitted_url=$(cat tmp.log | grep "success: result:" |cut -d ' ' -f4)
  # echo $submitted_url
  rm -f tmp.log
}


oj_submit_force(){
  local command=$1
  local level=$2

  local url=$(cat $level.cpp | grep "@url" | cut -d ' ' -f4)

  oj submit --language 3003 --no-guess --wait 0 --guess-cxx-compiler gcc --no-open --yes $url $level.cpp |& tee tmp.log
  readonly submitted_url=$(cat tmp.log | grep "success: result:" |cut -d ' ' -f4)
  # echo $submitted_url
  rm -f tmp.log
}


# @doc open <level> open AtCoder task page
open_problem_page(){
  local command=$1
  local level=$2

  local url=$(cat $level.cpp | grep "@url" | cut -d ' ' -f4)

  $open_browser $url
}


# @doc me <level> open AtCoder submission me page
open_submission_page(){
  local command=$1

  local url=$(cat a.cpp | grep "@url" | cut -d ' ' -f4)
  local id=$(echo $url | cut -d '/' -f7)
  local contest=$(echo $id | cut -d'_' -f1 | tr -cd '[a-z]\n')
  local contest_num=$(echo $id | tr -cd '0123456789\n')
  local submission_me="https://atcoder.jp/contests/${contest}${contest_num}/submissions/me"

  $open_browser $submission_me
}


# @doc pdf open AtCoder editorial pdf
open_editorial_pdf(){
  local command=$1
  local url=$(cat a.cpp | grep "@url" | cut -d ' ' -f4)
  local pdf_page=$(curl -s -H 'Accept-Language: ja' -XGET $url |grep pdf |cut -d '"' -f2)

  $open_browser $pdf_page
}


# @doc youtube AtCoder youtube live
open_youtube(){
  local command=$1
  local url=$(cat a.cpp | grep "@url" | cut -d ' ' -f4)
  local youtube_url=$(curl -s -H 'Accept-Language: ja' -XGET $url |grep youtube |cut -d '"' -f2)

  $open_browser $youtube_url
}


function main() {
  check_oj

  if [[ $# -lt 1 ]]; then
    echo "command is empty!!!"
    echo ""
    usage
  fi

  local COMMAND=$1

  case "$COMMAND" in
    "update" ) update_problem_json ;;
    "login" ) oj_login ;;
    "session" ) oj_session ;;
    "logout" ) oj_logout ;;
    "new" ) oj_new $@ ;;
    "dl" ) oj_download $@ ;;
    "dlsys" ) oj_download_sys $@ ;;
    "test" ) oj_test $@ ;;
    "sys" ) oj_system_test $@ ;;
    "system" ) oj_system_test $@ ;;
    "sub" ) oj_submit $@ && $path_to_atcoder/bin/monitor_submission.sh $submitted_url ;;
    "submit" ) oj_submit $@ && $path_to_atcoder/bin/monitor_submission.sh $submitted_url ;;
    "subforce" ) oj_submit_force $@ ;;
    "open" ) open_problem_page $@ ;;
    "me" ) open_submission_page $@ ;;
    "pdf" ) open_editorial_pdf $@ ;;
    "youtube" ) open_youtube $@ ;;
    "help" ) usage ;;
    * ) echo "something wrong" ;;
  esac
}

main $@
