#!/bin/bash
  2 
  3 on_ctrl_c() {
  4 echo "Ignoring Ctrl-C"
  5 }
  6 # Call on_ctrl_c() when the interrupt signal is received.
  7 # The interrupt signal is sent when you press Ctrl-C.
  8 trap on_ctrl_c INT
  9 
 10 mkfifo mypipe-$$
 11 
 12 cat mypipe-$$ | nc -l $1 | /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > mypi    pe-$$
 13 
 14 rm mypipe-$$
