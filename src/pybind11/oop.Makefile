
all:
	mkdir build; cd build; cmake ../oop; make; make install

clean:
	rm -rf build

