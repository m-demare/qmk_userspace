# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
LTO_ENABLE = yes
SWAP_HANDS_ENABLE = no
AUDIO_ENABLE = no

SRC = matrix.c
SRC += keydefs.c
SRC += features/vim_mode.c
SRC += features/compose.c
