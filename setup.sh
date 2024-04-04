#!/bin/bash

git clone https://github.com/qmk/qmk_firmware $HOME/localwork/qmk_firmware

pushd $HOME/localwork/qmk_firmware

git submodule update --init
qmk setup

popd

qmk config user.overlay_dir="$(realpath .)"
