CC = gcc
 
CFLAGS = -g -Wall 

mdb-lookup-server-nc-2: mdb-lookup-server-nc-2.o
 
mdb-lookup-server-nc-2.o: mdb-lookup-server-nc-2.c


.PHONY: mdb-lookup-server-nc-1
mdb-lookup-server-nc-1: mdb-lookup-server-nc-1.o

mdb-lookup-server-nc-1.o: mdb-lookup-server-nc-1.c
