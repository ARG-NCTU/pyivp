import pytest
from pyivp import XYSegList

def test_add_vertex():
    seg_list = XYSegList()
    seg_list.add_vertex(1.0, 2.0, 3.0, "vertex1")
    assert seg_list.get_vx(0) == 1.0
    assert seg_list.get_vy(0) == 2.0
    assert seg_list.get_vz(0) == 3.0
    assert seg_list.get_vprop(0) == "vertex1"

def test_delete_vertex():
    seg_list = XYSegList()
    seg_list.add_vertex(1.0, 2.0, 3.0, "vertex1")
    seg_list.add_vertex(2.0, 3.0, 4.0, "vertex2")
    seg_list.delete_vertex(1.0, 2.0)
    assert seg_list.get_vx(0) == 2.0
    assert seg_list.get_vy(0) == 3.0
    assert seg_list.get_vz(0) == 4.0
    assert seg_list.get_vprop(0) == "vertex2"

def test_get_vx():
    seg_list = XYSegList()
    seg_list.add_vertex(1.0, 2.0, 3.0, "vertex1")
    assert seg_list.get_vx(0) == 1.0
    assert seg_list.get_vx(1) == 0

def test_get_vy():
    seg_list = XYSegList()
    seg_list.add_vertex(1.0, 2.0, 3.0, "vertex1")
    assert seg_list.get_vy(0) == 2.0
    assert seg_list.get_vy(1) == 0

def test_get_vz():
    seg_list = XYSegList()
    seg_list.add_vertex(1.0, 2.0, 3.0, "vertex1")
    assert seg_list.get_vz(0) == 3.0
    assert seg_list.get_vz(1) == 0

def test_get_spec():
    seg_list = XYSegList()
    seg_list.add_vertex(1.0, 2.0, 3.0, "vertex1")
    seg_list.add_vertex(2.0, 3.0, 4.0, "vertex2")
    assert seg_list.get_spec(2, "") == "pts={1,2,3,vertex1:2,3,4,vertex2}"