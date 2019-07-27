#!/bin/bash
# @date Time-stamp: <2019-07-27 18:04:33 tagashira>
# @file install-oj.sh
# @brief

DOTFILES="$HOME/dotfiles"

if [ $(which porg) ]; then
    echo 'porg command found'
    porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
    echo ""
    ln -sf $(cd $(dirname $0) && pwd)/act.sh $HOME/bin/act && which act
    ln -sf $(cd $(dirname $0) && pwd)/dl_system_testcase.sh $HOME/bin/dl_sys && which dl_sys
else
    echo 'porg command not found ...'
    eval ${DOTFILES}/etc/init/00-install-porg.sh &&\
      porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
    echo ""
    ln -sf $(cd $(dirname $0) && pwd)/act.sh $HOME/bin/act && which act
    ln -sf $(cd $(dirname $0) && pwd)/dl_system_testcase.sh $HOME/bin/dl_sys && which dl_sys
fi
