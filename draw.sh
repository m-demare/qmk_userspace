#!/bin/bash
set -e

USERNAME=m-demare
KEYBOARD=zsa/moonlander
KEYMAP=keyboards/$KEYBOARD/keymaps/$USERNAME/keymap.c

DRAWING_FILE=/tmp/kb_drawing.svg


# Expanding
echo "Running preprocessor"
EXPANDED=`gcc -E -DDRAW_KEYMAP $KEYMAP`
EXPANDED=`echo "$EXPANDED" | sed -Ee '/^#/d;'`


# QMK parsing
echo "Running QMK parser"
pushd $HOME/localwork/qmk_firmware > /dev/null

RES=`echo $EXPANDED | qmk c2json -kb $KEYBOARD -km $USERNAME --no-cpp - | sed -Ee 's/ES_/KC_/g;'`

popd > /dev/null

USERSPACE=`pwd`


# keymap-drawer
echo "Running keymap-drawer parser"
pushd $HOME/localwork/keymap-drawer > /dev/null

RES=`echo "$RES" | poetry run keymap parse -l BASE VIMISH SYMBOLS NUMBERS "MOUSE AND MEDIA" GAMING -q -`

RES=`echo "$RES" | sed -Ee 's/h: BASE/h: PREV BUF/g;'`

echo "Drawing keymap"
echo "$RES" | poetry run keymap draw - > $DRAWING_FILE

popd > /dev/null


firefox --private-window $DRAWING_FILE

