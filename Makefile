hello: 
	echo "Hello World"


CBIN = /usr/bin/g++

run:
	mkdir -p build
	$(CBIN) main.cpp -o ./build/main_exec
	./build/main_exec
