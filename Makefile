.PHONY: build run

build:
	if [ ! -d build ]; then mkdir build; fi
	g++ -std=gnu++17 *.cc -o build/cometh

run:
	./build/cometh
