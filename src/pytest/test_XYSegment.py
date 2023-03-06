import pytest
from pyivp import XYSegment


def test_XYSegment_constructor():
    s = XYSegment()
    assert isinstance(s,XYSegment)
    assert s.get_spec()=='pts=0,0:0,0'

def test_XYSegment_get():
    o1 = XYSegment()
    o1.set(10,20,30,40)
    assert o1.get_spec()=='pts=10,20:30,40'
    assert o1.get_x1()==10.0
    assert o1.get_y1()==20.0
    assert o1.get_x2()==30.0
    assert o1.get_y2()==40.0

def test_XYSegment_shift_horz():
    o1 = XYSegment()
    o1.shift_horz(10)
    assert o1.get_spec()=='pts=10,0:10,0'

def test_XYSegment_shift_vert():
    o1 = XYSegment()
    o1.shift_vert(20)
    assert o1.get_spec()=='pts=0,20:0,20'

def test_XYSegment_reverse():
    o1 = XYSegment()
    o1.set(10,20,30,40)
    o1.reverse()
    assert o1.get_spec()=='pts=30,40:10,20'

def test_XYSegment_length():
    o1 = XYSegment()
    o1.set(0,0,3,4)
    assert o1.length()==5.0