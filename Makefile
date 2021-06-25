all:
	mkdir -p build
	cd build && cmake ..
	cd build && make

clean:
	rm -rf bin/ build/
