#!/usr/bin/env bash

CPLUS_INCLUDE_PATH="$(find $HOME/opt/vcpkg/packages -type d -name include | tr '\n' ':')" g++ --std=c++20 -o $(echo $1 | sed 's/.cpp//') $1
