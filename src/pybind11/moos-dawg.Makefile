
all:
	mkdir build; cd build; cmake ../moos-dawg-2024; make; make install

clean:
	rm -rf build

