hello: 
	echo "Hello World"


CBIN = /usr/bin/g++

run:
	mkdir -p build
	$(CBIN) main.cpp src/cpp/utils.cpp -o ./build/main_exec
	./build/main_exec
