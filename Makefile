
convert:
	qmk json2c map/keymap.json > default/keymap.c

compile:
	qmk compile  -e CONVERT_TO=liatris  -kb splitkb/aurora/sofle_v2/rev1 -km custom
