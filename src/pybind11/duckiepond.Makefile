
all:
	mkdir build; cd build; cmake ../duckiepond; make; make install

clean:
	rm -rf build

