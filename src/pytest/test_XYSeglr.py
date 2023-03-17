import pytest
from pyivp import XYSeglr

def test_constructor():
    xy_seglr = XYSeglr()
    assert xy_seglr.getRayLen() == 5
    assert xy_seglr.getHeadSize() == 3

def test_constructor_with_seglr():
    xy_seglr = XYSeglr()
    assert xy_seglr.getRayLen() == 5
    assert xy_seglr.getHeadSize() == 3

def test_clear():
    xy_seglr = XYSeglr()
    xy_seglr.clear()
    assert xy_seglr.getRayLen() == 5
    assert xy_seglr.getHeadSize() == 3

def test_setRayLen():
    xy_seglr = XYSeglr()
    xy_seglr.setRayLen(10)
    assert xy_seglr.getRayLen() == 10
    xy_seglr.setRayLen(-5)
    assert xy_seglr.getRayLen() == 0

def test_setHeadSize():
    xy_seglr = XYSeglr()
    xy_seglr.setHeadSize(5)
    assert xy_seglr.getHeadSize() == 5
    xy_seglr.setHeadSize(-3)
    assert xy_seglr.getHeadSize() == 0

def test_valid():
    xy_seglr = XYSeglr()
    assert xy_seglr.valid() == False

def test_getRayBaseX():
    xy_seglr = XYSeglr()
    assert xy_seglr.getRayBaseX() == 0

def test_getRayBaseY():
    xy_seglr = XYSeglr()
    assert xy_seglr.getRayBaseY() == 0

def test_get_spec():
    xy_seglr = XYSeglr()
    assert xy_seglr.get_spec(1) == "pts={},ray=0.0,ray_len=5,head_size=3"