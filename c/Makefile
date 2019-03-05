# Nice Makefiles tutorial:
# https://www.youtube.com/watch?v=_r7i5X0rXJk

all: readstrings playgl playstrtok scopenread udsock_srv

readstrings: readstrings.c
	gcc readstrings.c -o build/readstrings

playgl: playgl.c
	gcc playgl.c -o build/playgl

playstrtok: playstrtok.c
	gcc playstrtok.c -o build/playstrtok

scopenread: scopenread.c
	gcc scopenread.c -o build/scopenread

udsock_srv: udsock_srv.c
	gcc udsock_srv.c -o build/udsock_srv

clean:
	rm build/*