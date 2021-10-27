#1.#!bin/bash
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"./lib"
export LD_LIBRARY_PATH
exec "./some2.exe"
