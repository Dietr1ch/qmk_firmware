default: build

clean:
    make clean


build:
    qmk compile -kb 'ergodox_ez/base' -km 'Dietr1ch'

flash:
    qmk flash -kb 'ergodox_ez/base' -km 'Dietr1ch'
