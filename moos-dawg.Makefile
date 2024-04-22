## Makefile for pyivp                                                               

all: build-ivp tests

build-ivp:
	make -C src
	make -C src_unit_tests 
	make -C src/pybind11 -f moos-dawg.Makefile

tests:
	cd src_unit_tests; ./alltest.sh
	cd src/pytest; python3 test_pattern_block.py

pypi: dist
	#python3 -m twine upload --skip-existing --repository pypi dist/*.tar.gz
	python3 -m twine upload --skip-existing --repository pypi dist/*

dist: build-ivp
	python3 setup.py sdist bdist_wheel

clean:
	make -C src clean
	make -C  src_unit_tests clean
	make -C src/pybind11 clean -f moos-dawg.Makefile
