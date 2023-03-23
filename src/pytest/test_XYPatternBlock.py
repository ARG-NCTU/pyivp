import pytest
from pyivp import XYPatternBlock,XYPoint
import pyivp
def test_XYPatternBlock_constructor():
    block = XYPatternBlock()
    assert isinstance(block, XYPatternBlock)

def test_XYPatternBlock_set_param():
    block = XYPatternBlock()
    assert block.set_param("block_width", 40)
    assert block.set_param("block_length", 10)
    assert block.set_param("swath_width", 10)
    assert block.set_param("angle", 10)

def test_XYPatternBlock_distance_to_closestentry():
    block = XYPatternBlock()
    block.set_param("block_width", 40)
    block.set_param("id_point","30,30")

    dist_entry = block.distance_to_closestentry(osx = 10, osy = 30, any_segment = True) 
    assert dist_entry == 40.0

def test_XYPatternBlock_distance_to_crossaxis():
    block = XYPatternBlock()
    block.set_param("block_width", 50)
    block.set_param("id_point","30,30")

    dist_crossAxis = block.distance_to_crossaxis(30, 30)
    assert dist_crossAxis == -1