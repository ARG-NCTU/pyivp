# pyivp (IvP for Python)

This repo is to set up the pybind11 for the IvP libraries in [MOOS-IvP](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php)

In particular we make a copy of parts of the ivp source files:
* pyivp/src/lib_geometry
* pyivp/src/lib_mbutils
* pyivp/src_unit_tests/

We intented to use pybind11 to create
* ivp/pybind11/

For the use of well-established functions.

## Environment and Installation

We will use Docker to manage the dependencies, which should be minimal.
Docker mounts the volumn ~/pyivp between the host and container.

To get started:
```
git clone git@github.com:ARG-NCTU/pyivp.git
cd ~/pyivp
source docker_run.sh
```

Note that we should compile and run in Docker.
We use a root account in order to access driver and other hardware.
Therefore, everything edited in container will belong to root.

We suggest to edit code in host.


## cpplabs examples

This is an example based on 2.680 CPP Labs (lab05 and lab06)

### 

```
source docker_run.sh
cd ~/pyivp/examples/cpplabs
make
```

Note that we will compile the lib_geometry and install it to /usr/local/lib, 
which is inside container. (so no worries to mess up your own system)


## XYPatternBlock

<img width="585" alt="image" src="https://user-images.githubusercontent.com/16217256/171214864-ec5ffca7-fe53-4dbb-ae7d-e058462d8606.png">

## XYHexgon

<img width="585" alt="image" src="https://user-images.githubusercontent.com/16217256/171215267-8daf38af-e1a4-4843-8791-481a334c0983.png">

## Class Diagram

The class diagram is drawn by [DotUML](https://dotuml.com/)

Parts of the diagram is shown below:

<img width="554" alt="image" src="https://user-images.githubusercontent.com/16217256/171215939-077bd36b-438d-4460-ba8e-20a8521784c4.png">

## pybind11 example

```
source docker_run.sh
cd example
make
python3 pytest/test.py
```

You should see:

```
Made a bike called: Yamaha
Zoom Zoom on road: mullholland
```
without import errors or assert fails


