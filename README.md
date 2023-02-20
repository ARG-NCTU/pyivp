# pyivp (IvP for Python)

This repo is to set up the pybind11 for the IvP libraries in [MOOS-IvP](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php)

In particular we make a copy of parts of the ivp source files:
* pyivp/src/lib_geometry
* pyivp/src/lib_mbutils
* pyivp/src_unit_tests/

We intented to use pybind11 to create
* ivp/pybind11/

For the use of well-established functions.

## Docker and Repos 

We will use Docker to manage the dependencies, which should be minimal.
Docker mounts the volumn ~/pyivp between the host and container.

We will also use [movinngpandas]()https://github.com/ARG-NCTU/movingpandas

To get started:
```
git clone --recursive git@github.com:ARG-NCTU/pyivp.git
cd ~/pyivp
source docker_run.sh
```

Or 
```
source docker_join.sh
```
Note that we should compile and run in Docker.
We use a root account in order to access driver and other hardware.
Therefore, everything edited in container will belong to root.

We suggest to edit code in host.


### nbdev

The pyivp repo has been configured to a [nbdev](https://nbdev.fast.ai/) repo. 
Quote from nbdev
```
nbdev is a library that allows you to develop a python library in Jupyter Notebooks, putting all your code, tests and documentation in one place. That is: you now have a true literate programming environment, as envisioned by Donald Knuth back in 1983!
```
We will use nbdev to develop "high-level" API based on IvP and test all ivp libraries in Jupyter Notebook.

After you compile and install the library.
```
source Docker/colab_jupyter.sh
```

Open a browser, and enter the following
```
http://127.0.0.1:8888/tree
```
Now you could open and enjoy IvP in Jupyter Notebooks.

```
nbdev_clean_nbs
```
Remember to run this command to clear notebooks

## Geometry Utilities
The [documentation](https://oceanai.mit.edu/ivpman/pmwiki/pmwiki.php?n=IvPTools.Geometry) shows how to use functions in ivp.
### XYPatternBlock

<img width="585" alt="image" src="https://user-images.githubusercontent.com/16217256/171214864-ec5ffca7-fe53-4dbb-ae7d-e058462d8606.png">

```
import pyivp
```

```
pattern = pyivp.string2SegList("format=lawnmower, x=0, y=0, height=60, width=180, lane_width=15, rows=north-south, startx=20, starty=-300, degs=45")
```

- must use `format=lawnmower` for pattern block.
- there is 4 entry, and (startx, starty) will decide where is the closest entry.

### XYPolygon

<img width="585" alt="image" src="https://user-images.githubusercontent.com/16217256/171215267-8daf38af-e1a4-4843-8791-481a334c0983.png">

``` 
import pyivp
``` 

``` 
waypointPloy = pyivp.string2ploy("example")
``` 

- example => `x=0, y=0, format=radial, radius=10, pts=4`
- you can pass args such as : must have -> [x, y, z, radius, pts], snap, label, active, msg
- snap means the size of the grid, and the ploy's vertex will stick on the grid.
``` 
waypointSeg = waypointPloy.exportSegList(x0, y0)
``` 

- Build an XYSegList from the poly. Make the first point closest to the x0, y0.
``` 
waypointSeg.get_spec_pts()
``` 

- this will print the vertexs of ploy (clockwise!!) such as 'pts={-1,1:-1,-1:1,-1:1,1}'
- you can use waypointSeg.reverse() or waypointPloy.reverse() for counterclockwise
- you can use waypointSeg.is_clockwise() to check.
``` 
waypointSeg.get_vx() and waypointSeg.get_vy() 
```

- with for loop to get every vertex's information.

## Class Diagram

The class diagram is drawn by [DotUML](https://dotuml.com/)

Parts of the diagram is shown below:

<img width="554" alt="image" src="https://user-images.githubusercontent.com/16217256/171215939-077bd36b-438d-4460-ba8e-20a8521784c4.png">




