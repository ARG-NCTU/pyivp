import pytest
from pyivp import EdgeTagSet, EdgeTag

def test_EdgeTagSet_constructor():
    e = EdgeTagSet()
    assert isinstance(e, EdgeTagSet)

def test_EdgeTagSet_add_edge_tag():
    e = EdgeTagSet()
    assert e.add_edge_tag(EdgeTag(1, 2, "test"))
    assert not e.add_edge_tag(EdgeTag(1, 2, ""))

def test_EdgeTagSet_set_on_spec():
    e = EdgeTagSet()
    e.set_on_spec("tags={2:3:end#4:5:end#6:7:end}")
    assert not e.set_on_spec("invalid string")

def test_EdgeTagSet_get_spec():
    e = EdgeTagSet()
    assert e.get_spec() == ""
    e.set_on_spec("tags={2:3:end#4:5:end#6:7:end}")
    assert e.get_spec() == "tags={2:3:end#4:5:end#6:7:end}"

def test_EdgeTagSet_matches():
    e = EdgeTagSet()
    e.set_on_spec("tags={2:3:end#4:5:end#6:7:end}")
    assert e.matches(2, 3, "end")
    assert e.matches(4, 5, "end")
    assert not e.matches(8, 9, "end")

# def test_EdgeTagSet_print(capsys):
#     e = EdgeTagSet()
#     e.set_on_spec("tags={2:3:end#4:5:end#6:7:end}")
#     e.print()
#     captured = capsys.readouterr()
#     assert captured.out == "EdgeTagSet: 3 tags\n2 -> 3: end\n4 -> 5: end\n6 -> 7: end\n"