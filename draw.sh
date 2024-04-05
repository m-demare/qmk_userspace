#!/bin/bash

USERNAME=m-demare
KEYBOARD=zsa/moonlander
KEYMAP=keyboards/$KEYBOARD/keymaps/$USERNAME/keymap.c

ABS_KEYMAP=`echo "$(realpath $KEYMAP)"`
DRAWING_FILE=/tmp/kb_drawing.svg

cp $KEYMAP $KEYMAP.bak


# Expanding
sed -i -Ee '/^#include.++/d;' $KEYMAP  # Delete qmk includes (they won't be found)
sed -i -Ee '1s/^/#include "layout_mdemare.h"\n#define LAYOUT_moonlander LAYOUT\n/;' $KEYMAP  # Add necessary includes
sed -i -Ee '1s/^/#define QWERTY 0\n#define VIMISH 1\n#define SYMBOLS 2\n#define NUMBERS 3\n#define MOUSE_AND_MEDIA 4\n#define GAMING 5\n/;' $KEYMAP  # Translate layer enum to numbers

EXPANDED=`gcc -E $KEYMAP`
EXPANDED=`echo "$EXPANDED" | sed -Ee '/^#/d;'`

echo "$EXPANDED" > $KEYMAP


# QMK parsing
pushd $HOME/localwork/qmk_firmware > /dev/null

RES=`qmk c2json -kb $KEYBOARD -km $USERNAME --no-cpp $ABS_KEYMAP`

popd > /dev/null

USERSPACE=`pwd`


# keymap-drawer
pushd $HOME/localwork/keymap-drawer > /dev/null

RES=`echo "$RES" | poetry run keymap parse -l BASE VIMISH SYMBOLS NUMBERS "MOUSE AND MEDIA" GAMING -q -`

RES=`echo "$RES" | sed -Ee 's/C\(GRAVE\)/C\(\`\)/g;s/h: BASE/h: PREV BUF/g;'`

echo "$RES" | poetry run keymap draw - > $DRAWING_FILE

popd > /dev/null


firefox --private-window $DRAWING_FILE

mv -f $KEYMAP.bak $KEYMAP
