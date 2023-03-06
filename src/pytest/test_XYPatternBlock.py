import pytest
from pyivp import XYPatternBlock,XYPoint
import pyivp
def test_XYPatternBlock_constructor():
    block = XYPatternBlock()
    assert isinstance(block, XYPatternBlock)

def test_XYPatternBlock_setParam():
    block = XYPatternBlock()
    assert block.setParam("block_width", 40)
    assert block.setParam("block_length", 10)
    assert block.setParam("swath_width", 10)
    assert block.setParam("angle", 10)

def test_XYPatternBlock_distanceToClosestEntry():
    block = XYPatternBlock()
    block.setParam("block_width", 40)
    block.setParam("id_point","30,30")

    dist_entry = block.distanceToClosestEntry(osx = 10, osy = 30, any_segment = True) 
    assert dist_entry == 40.0

def test_XYPatternBlock_distanceToCrossAxis():
    block = XYPatternBlock()
    block.setParam("block_width", 50)
    block.setParam("id_point","30,30")

    dist_crossAxis = block.distanceToCrossAxis(30, 30)
    assert dist_crossAxis == -1