.PHONY: build build-release run run-release setup clean remove_build

run: build
	@./build/bin/ctmpd/ctmpd

run-release: build-release
	@./build/bin/ctmpd/ctmpd

build:
	@mkdir -p build
	@cd build && cmake --build . --config=Debug

build-release:
	@mkdir -p build
	@cd build && cmake --build . --config=Release

setup: clean

clean: remove_build
	@mkdir -p build
	@cd build && cmake .. -G Ninja

remove_build: 
	rm -rf build