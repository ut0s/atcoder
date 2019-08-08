#!/bin/bash
# @file monitor_submission.sh
# @brief monitor AtCoder submission


path_to_icon="$(cd $(dirname $0) && cd ../etc && pwd)/.icon.png"

NOTIFIY_COMMAND="notify-send"
NOTIFIY_COMMAND_OPT=" -u normal --icon=${path_to_icon}"

LAP=3 #seconds
count=0

init(){
  url_icon="https://img.atcoder.jp/assets/atcoder.png"

  if [ -e $path_to_icon ]
  then
    :
  else
    curl -s $url_icon -o $path_to_icon
  fi
}

get_status(){
  local url=$1
  local status=$(curl -s $url | grep "judge-status" |cut -d "\"" -f 7 | cut -d "<" -f1 | cut -d ">" -f2)
  echo $status
}

get_contest_title(){
  local url=$1
  local contest_title=$(curl -s $url | grep "contest-title" |cut -d ">" -f 3 | cut -d "<" -f1)
  echo $contest_title
}


get_problem_name(){
  local url=$1
  local problem_name=$(curl -s $url | grep -A2 "<th>Task" |cut -d ">" -f3 | cut -d "<" -f1)
  echo $problem_name
}


notify_submission(){
  local url=$1
  local status=$(get_status $url)
  local contest_title=$(get_contest_title $url)
  local problem_name=$(get_problem_name $url)

  local message="$contest_title | $problem_name"
  ${NOTIFIY_COMMAND} ${NOTIFIY_COMMAND_OPT} $status "$message" > /dev/null
  echo $status
}

main(){
  init
  while true; do
    res=$(get_status $@)
    if [ "$res" = "AC" ] || [ "$res" = "RE" ] || [ "$res" = "TLE" ] || [ "$res" = "WA" ] || [ "$res" = "CE" ]
    then
      echo ""
      notify_submission $@
      exit 0
    else
      echo -n "..."
      sleep $LAP"s"
      count=$(( $count + 1 ))
      if [ $count -eq 10 ]
      then
        echo "30 seconds elapsed"
        exit 1
      fi

    fi
  done
}

main $@

# test
# get_status $@
# get_contest_title $@
# get_problem_name $@
