#!/bin/bash
# @file install-oj.sh
# @brief

DOTFILES="$HOME/dotfiles"

if [ $(which porg) ]; then
    echo 'porg command found'
    porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
    porg -l -p online-judge-api "pip3 install -U online-judge-api-client"
    echo ""
    ln -sf $(cd $(dirname $0) && pwd)/act.sh $HOME/bin/act && which act
    ln -sf $(cd $(dirname $0) && pwd)/dl_system_testcase.sh $HOME/bin/dl_sys && which dl_sys
else
    echo 'porg command not found ...'
    eval ${DOTFILES}/etc/init/00-install-porg.sh &&\
      porg -l -p online-judge-tools "pip3 install -U online-judge-tools --user"
      porg -l -p online-judge-api "pip3 install -U online-judge-api-client"
    echo ""
    ln -sf $(cd $(dirname $0) && pwd)/act.sh $HOME/bin/act && which act
    ln -sf $(cd $(dirname $0) && pwd)/dl_system_testcase.sh $HOME/bin/dl_sys && which dl_sys
fi

which g++ || ln -fs /opt/homebrew/Cellar/gcc/11*/bin/aarch64-apple-darwin21-g++-11 /usr/local/bin/g++
