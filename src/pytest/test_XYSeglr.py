import pytest
from pyivp import XYSeglr

def test_constructor():
    xy_seglr = XYSeglr()
    assert xy_seglr.get_raylen() == 5
    assert xy_seglr.get_headsize() == 3

def test_constructor_with_seglr():
    xy_seglr = XYSeglr()
    assert xy_seglr.get_raylen() == 5
    assert xy_seglr.get_headsize() == 3

def test_clear():
    xy_seglr = XYSeglr()
    xy_seglr.clear()
    assert xy_seglr.get_raylen() == 5
    assert xy_seglr.get_headsize() == 3

def test_set_raylen():
    xy_seglr = XYSeglr()
    xy_seglr.set_raylen(10)
    assert xy_seglr.get_raylen() == 10
    xy_seglr.set_raylen(-5)
    assert xy_seglr.get_raylen() == 0

def test_set_headsize():
    xy_seglr = XYSeglr()
    xy_seglr.set_headsize(5)
    assert xy_seglr.get_headsize() == 5
    xy_seglr.set_headsize(-3)
    assert xy_seglr.get_headsize() == 0

def test_valid():
    xy_seglr = XYSeglr()
    assert xy_seglr.valid() == False

def test_get_raybasex():
    xy_seglr = XYSeglr()
    assert xy_seglr.get_raybasex() == 0

def test_get_raybasey():
    xy_seglr = XYSeglr()
    assert xy_seglr.get_raybasey() == 0

def test_get_spec():
    xy_seglr = XYSeglr()
    assert xy_seglr.get_spec(1) == "pts={},ray=0.0,ray_len=5,head_size=3"