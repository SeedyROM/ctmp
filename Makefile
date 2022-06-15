.PHONY: run setup clean remove_build

run:
	@mkdir -p build
	@cd build && ninja
	@./build/bin/ctmpd/ctmpd

setup: clean

clean: remove_build
	@mkdir -p build
	@cd build && cmake .. -G Ninja

remove_build: 
	rm -rf build