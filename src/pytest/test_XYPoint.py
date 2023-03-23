import pytest
from pyivp import XYPoint


def test_initialization():
    point = XYPoint()
    assert point.x() == 0
    assert point.y() == 0
    assert point.z() == 0
    assert not point.valid()

    point = XYPoint(1, 2)
    assert point.x() == 1
    assert point.y() == 2
    assert point.z() == 0
    assert point.valid()


def test_setters():
    point = XYPoint()
    point.set_vertex(1, 2, 3)
    assert point.x() == 1
    assert point.y() == 2
    assert point.z() == 3
    assert point.valid()

    point.set_vx(4)
    assert point.x() == 4

    point.set_vy(5)
    assert point.y() == 5

    point.set_vz(6)
    assert point.z() == 6


def test_shift():
    point = XYPoint(1, 2)
    point.shift_x(1)
    assert point.x() == 2

    point.shift_y(-1)
    assert point.y() == 1


def test_spec_digits():
    point = XYPoint()
    point.set_spec_digits(4)
    assert point.get_spec() == "x=0,y=0"

    point.set_vertex(1.2345, 2.3456, 3.4567)
    assert point.get_spec() == "x=1.2345,y=2.3456,z=3.4567"


def test_project_pt():
    point1 = XYPoint(1, 2)
    point2 = XYPoint(3, 4)
    point2.project_pt(point1, 45, 2)
    assert round(point2.x(), 2) == 2.41
    assert round(point2.y(), 2) == 3.41
    assert point2.z() == 0
