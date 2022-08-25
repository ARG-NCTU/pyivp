
all:
	mkdir build; cd build; cmake ../robotx; make; make install

clean:
	rm -rf build

