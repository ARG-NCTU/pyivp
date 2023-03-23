import pytest
from pyivp import XYVector

def test_XYVector_construction():
    vec1 = XYVector()
    assert vec1.xpos() == 0
    assert vec1.ypos() == 0
    assert vec1.mag() == 0
    assert vec1.ang() == 0
    assert vec1.xdot() == 0
    assert vec1.ydot() == 0
    assert not vec1.valid()
    assert vec1.headsize() == -1

def test_clear():
    v = XYVector(1, 2, 3, 4)
    v.clear()
    assert v.xpos() == 0
    assert v.ypos() == 0
    assert v.mag() == 0
    assert v.ang() == 0
    assert v.xdot() == 0
    assert v.ydot() == 0
    assert v.valid() is False
    assert v.headsize() == -1


def test_apply_snap():
    v = XYVector(1.2, 2.5, 3.8, 4.1)
    v.apply_snap(0.5)
    assert v.xpos() == 1
    assert v.ypos() == 2.5


def test_aug_magnitude():
    v = XYVector(1, 2, 3, 4)
    v.aug_magnitude(2)
    assert v.mag() == 5


def test_aug_angle():
    v = XYVector(1, 2, 3, 4)
    v.aug_angle(45)
    assert round(v.ang(), 5) == 49.0


def test_set_position():
    v = XYVector()
    v.set_position(1, 2)
    assert v.xpos() == 1
    assert v.ypos() == 2
    assert v.valid() is True


def test_set_vector_xy():
    v = XYVector()
    v.set_vector_xy(3, 4)
    assert v.xdot() == 3
    assert v.ydot() == 4
    assert round(v.mag(), 5) == 5


def test_set_vector_ma():
    v = XYVector()
    v.set_vector_ma(3, 45)
    assert round(v.xdot(), 5) == 2.12132
    assert round(v.ydot(), 5) == 2.12132
    assert v.mag() == 3
    assert v.ang() == 45


def test_merge_vector_xy():
    v = XYVector(1, 2, 3, 4)
    v.merge_vector_xy(5, 6)
    assert round(v.xdot(), 5) == 5.20927
    assert round(v.ydot(), 5) == 8.99269
    assert round(v.mag(), 5) == 10.39255
    assert round(v.ang(), 5) == 30.08277


def merge_vector_ma():
    v = XYVector(1, 2, 3, 4)
    v.merge_vector_ma(2, 45)
    assert round(v.xdot(), 5) == 1.62348
    assert round(v.ydot(), 5) == 4.40691
    assert round(v.mag(), 5) == 4.69644
    assert round(v.ang(), 5) == 20.22356


def test_get_spec():
    v = XYVector(1.2, 2.5, 3.8, 4.1)
    assert v.get_spec("active=true") == "x=1.2,y=2.5,ang=4.1,mag=3.8,active=true"
    # assert v.get_spec("object") == ""