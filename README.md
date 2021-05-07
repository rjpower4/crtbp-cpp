# crtbp-cpp

This is a simple program demonstrating how to use the Boost C++ libraries to perform integration of the Circular Restricted Three Body Problem (CRTPB) equations of motion.

## Dependencies

The only dependency for this program is `libboost >= 1.71`.

## Building

Building requires the `meson` build system and is done via the commands:

``` sh
meson build
meson compile -C build
```

Then the tests can be run via
``` sh
cd ./build
ninja test
```
