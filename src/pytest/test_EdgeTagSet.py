import pytest
from pyivp import EdgeTagSet, EdgeTag

def test_EdgeTagSet_constructor():
    e = EdgeTagSet()
    assert isinstance(e, EdgeTagSet)

def test_EdgeTagSet_addEdgeTag():
    e = EdgeTagSet()
    assert e.addEdgeTag(EdgeTag(1, 2, "test"))
    assert not e.addEdgeTag(EdgeTag(1, 2, ""))

def test_EdgeTagSet_setOnSpec():
    e = EdgeTagSet()
    e.setOnSpec("tags={2:3:end#4:5:end#6:7:end}")
    assert not e.setOnSpec("invalid string")

def test_EdgeTagSet_getSpec():
    e = EdgeTagSet()
    assert e.getSpec() == ""
    e.setOnSpec("tags={2:3:end#4:5:end#6:7:end}")
    assert e.getSpec() == "tags={2:3:end#4:5:end#6:7:end}"

def test_EdgeTagSet_matches():
    e = EdgeTagSet()
    e.setOnSpec("tags={2:3:end#4:5:end#6:7:end}")
    assert e.matches(2, 3, "end")
    assert e.matches(4, 5, "end")
    assert not e.matches(8, 9, "end")

# def test_EdgeTagSet_print(capsys):
#     e = EdgeTagSet()
#     e.setOnSpec("tags={2:3:end#4:5:end#6:7:end}")
#     e.print()
#     captured = capsys.readouterr()
#     assert captured.out == "EdgeTagSet: 3 tags\n2 -> 3: end\n4 -> 5: end\n6 -> 7: end\n"