# RCX wrapper for the Transterpreter

This is a revised port of the RCX to the newer (2008-) wrapper architecture and source tree of the Transterpreter (http://www.transterpreter.org/). Portions of code have been re-used from BrickOS, as with the original port.

## Pre-requisites

* Debian 5 - packages `gcc-h8300-hms` and `binutils-h8300-hms` required on top of a system that can otherwise build the source tree natively. This setup is tested.

* Ubuntu 10.04 LTS (Lucid Lynx) currently broken, as source package `gcc-h8300-hms` cannot be built. This appears to be due to enabled security options with the compiler (https://wiki.ubuntu.com/CompilerFlags). Investigations continue.

## Building

Run `./build.sh` from the wrapper directory.