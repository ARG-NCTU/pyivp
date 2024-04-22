
all:
	mkdir build; cd build; cmake ../moos-dawg; make; make install

clean:
	rm -rf build

