.PHONY: run setup

run:
	@mkdir -p build
	@cd build && ninja
	@./build/bin/ctmpd/ctmpd

setup:
	@mkdir -p build
	@cd build; cmake . -G Ninja

clean: 
	rm -rf build