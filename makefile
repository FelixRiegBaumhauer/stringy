strtest: runner.c
	gcc runner.c -o strtest

run: strtest
	./strtest
