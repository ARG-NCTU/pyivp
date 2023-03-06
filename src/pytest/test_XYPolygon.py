import pytest
from pyivp import XYPolygon

def test_XYPolygon_constructor():
    p = XYPolygon()
    assert isinstance(p, XYPolygon)

def test_XYPolygon_add_vertex():
    p = XYPolygon()
    assert p.add_vertex(0, 0, True)==False
    assert p.add_vertex(1, 0, True)==False
    assert p.add_vertex(0, 1, True)==True

def test_XYPolygon_insert_vertex():
    polygon = XYPolygon()
    polygon.add_vertex(0, 0, True)
    polygon.add_vertex(1, 0, True)
    polygon.add_vertex(1, 1, True)
    polygon.add_vertex(0, 1, True)

    assert polygon.insert_vertex(0.5, 1, 0)

def test_XYPolygon_apply_snap():
    polygon = XYPolygon()
    polygon.add_vertex(0, 0, True)
    polygon.add_vertex(1, 0, True)
    polygon.add_vertex(1, 1, True)
    polygon.add_vertex(0, 1, True)

    assert polygon.apply_snap(1)

def test_XYPolygon_contains():
    polygon = XYPolygon()
    polygon.add_vertex(0, 0, True)
    polygon.add_vertex(1, 0, True)
    polygon.add_vertex(1, 1, True)
    polygon.add_vertex(0, 1, True)

    assert polygon.contains(0, 0)
    assert polygon.contains(2, 0)==False

def test_XYPolygon_dist_to_poly():
    polygon = XYPolygon()
    polygon.add_vertex(0, 0, True)
    polygon.add_vertex(1, 0, True)
    polygon.add_vertex(1, 1, True)
    polygon.add_vertex(0, 1, True)

    assert polygon.dist_to_poly(1.5, 0.5)==0.5
     
def test_XYPolygon_area():
    polygon = XYPolygon()
    polygon.add_vertex(0, 0, True)
    polygon.add_vertex(1, 0, True)
    polygon.add_vertex(1, 1, True)
    polygon.add_vertex(0, 1, True)

    assert polygon.area()==1.0