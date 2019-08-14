#!/bin/bash
# @date Time-stamp: <2019-08-14 13:26:36 tagashira>
# @file dl_system_testcase.sh
# @brief AtCoder Testcase Downloader

set -ue

readonly dropbox_static="https://www.dropbox.com/sh/arnpe0ef5wds8cv/"
readonly UA="user-agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36"

readonly path_to_cache="$HOME/atcoder/etc/"


function usage() {
  cat <<EOS
Usage:
  $0 COMMAND

  COMMAND      <contest_id>, update
EOS
  echo ""
  cat $0 | grep "@doc" |cut -d ' ' -f2- |tail -n +2

  exit 0
}


# @doc update testcase link in Dropbox folder
update_dropbox_link(){
  ping -c 1 google.com > /dev/null &&\
  google-chrome --headless --disable-gpu --dump-dom --virtual-time-budget=10000 "https://www.dropbox.com/sh/arnpe0ef5wds8cv/AAAk_SECQ2Nc6SVGii3rHX6Fa?dl=0" | sed -e "s#<#\n#g" -e "s#\\\#\n#g" -e "s#\"#\n#g" | grep $dropbox_static |sort -d |uniq > $path_to_cache/.dropbox_link.info && echo "Update Done"
}


check_testcase_exist(){
  local query=$1
  cat $path_to_cache/.dropbox_link.info | grep ${query^^} > /dev/null && echo "true" || echo "false"
}


obtain_contest_link(){
  local query=$1
  local isExist=$(check_testcase_exist $query)
  if [ $isExist = "true" ]
  then
    par_link=$(cat $path_to_cache/.dropbox_link.info | grep ${query^^})
    echo $par_link
  elif [ $isExist = "false" ]
  then
    echo "testcase doesn't exist OR wrong contest_id"
  fi
}


obtain_problem_link(){
  local contest_id=$1
  local par_link=$2

  curl -k -s -H 'accept-encoding: gzip, deflate, br' -H $UA -H 'content-type: application/json' $par_link --compressed |sed -e "s#<#\n#g" -e "s#\\\#\n#g" -e "s#\"#\n#g" | grep $dropbox_static |sort -d |uniq |grep "${contest_id^^}/"
}


dl_testcase_in_out(){
  local contest_id=$1
  local par_link=$2

  for problem_link in $(obtain_problem_link $contest_id $par_link); do
    for in_out_link in $(curl -k -s -H 'accept-encoding: gzip, deflate, br' -H $UA -H 'content-type: application/json' "${problem_link}" --compressed | sed -e "s#<#\n#g" -e "s#\\\#\n#g" -e "s#\"#\n#g" | grep $dropbox_static | grep -e "/out" -e "/in" | sort -d | uniq ); do
      local level=$(echo $in_out_link | cut -d '/' -f8 )
      mkdir -p system/${level,,}
      for dl_link in $(curl -k -s -H 'accept-encoding: gzip, deflate, br' -H $UA -H 'content-type: application/json' "${in_out_link}" --compressed | sed -e "s#<#\n#g" -e "s#\\\#\n#g" -e "s#\"#\n#g" | grep $dropbox_static | grep -e "/out/" -e "/in/" | sort -d | uniq); do
        local filename=$(echo $dl_link |cut -d '/' -f10 | cut -d '?' -f1)
        echo "$level/$filename"
        echo $dl_link | grep "/in/" > /dev/null && curl -sL $dl_link -o system/${level,,}/${filename}.in  &
        echo $dl_link | grep "/out/" > /dev/null && curl -sL $dl_link -o system/${level,,}/${filename}.out &
      done
      wait
    done
  done
}


# @doc <contest_id> download system test case
main(){
  if [[ $# -ne 1 ]]; then
    echo "parameter is wrong"
    echo ""
    usage
  elif [[ $1 = "update" ]]
  then
    update_dropbox_link
    exit 0
  fi

  local contest_id=$1
  local contest=$(echo $contest_id | tr -cd '[a-z]\n')
  local contest_num=$(echo $contest_id | tr -cd '0123456789\n')

  if [ -f $path_to_cache/.dropbox_link.info ]
  then
    :
  else
    update_dropbox_link || exit 1
  fi

  echo "Download ${contest^^}${contest_num} system testcase ..."
  obtain_contest_link $contest_id && dl_testcase_in_out $contest_id $(obtain_contest_link $contest_id)
}


test(){
  echo -e "\\e[31;47mcheck_testcase_exist\e[m"
  check_testcase_exist abc126
  check_testcase_exist agc015
  check_testcase_exist abc015
  echo ""
  echo -e "\e[31;47mobtain_contest_link\e[m"
  obtain_contest_link abc126
  # obtain_contest_link abc015 # exit 0
  echo ""
  echo -e "\e[31;47mobtain_problem_link\e[m"
  obtain_problem_link abc126 $(obtain_contest_link abc126)
  echo ""
  echo -e "\e[31;47mdl_testcase_in_out\e[m"
  dl_testcase_in_out abc126 $(obtain_contest_link abc126)
}

main $@
# test $@
