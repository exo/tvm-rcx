#!/bin/sh -e
# Compile firmware for Lego Mindstorms RCX

if [ ! -e ../../runtime/libtvm/configure ]; then
    echo Make sure the rest of the toolchain is built first
    exit
fi

make -k distclean || true

unset ACLOCAL
autoreconf -vfi

./configure \
    --host=h8300-hitachi-coff \
    "$@"
make
