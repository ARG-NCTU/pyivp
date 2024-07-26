
all:
	mkdir build; cd build; cmake ../drone; make; make install

clean:
	rm -rf build

