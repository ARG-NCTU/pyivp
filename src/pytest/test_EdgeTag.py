import pytest
from pyivp import EdgeTag

def test_constructor_no_indices():
    et = EdgeTag()
    assert et.valid() == False

def test_constructor_invalid_indices():
    et = EdgeTag(0, 3, "tag")
    assert et.valid() == False

    et = EdgeTag(3, 0, "tag")
    assert et.valid() == False

def test_constructor_valid_indices():
    et = EdgeTag(0, 1, "tag")
    assert et.valid() == True

    et = EdgeTag(1, 0, "tag")
    assert et.valid() == True

def test_constructor_invalid_tag():
    et = EdgeTag(0, 1, "")
    assert et.valid() == False

def test_constructor_valid_tag():
    et = EdgeTag(0, 1, "tag")
    assert et.valid() == True

def test_getSpec():
    et = EdgeTag(0, 1, "tag")
    assert et.get_spec() == "0:1:tag"

def test_set_on_spec_invalid():
    et = EdgeTag()
    assert et.set_on_spec("invalid_spec") == False

    et = EdgeTag()
    assert et.set_on_spec("0:1") == False

    et = EdgeTag()
    assert et.set_on_spec("0::tag") == False

    et = EdgeTag()
    assert et.set_on_spec("0:1:") == False

    et = EdgeTag()
    assert et.set_on_spec(":0:1:tag") == False

    et = EdgeTag()
    assert et.set_on_spec("0.5:1:tag") == True

    et = EdgeTag()
    assert et.set_on_spec("0:1.5:tag") == True

def test_set_on_spec_valid():
    et = EdgeTag()
    assert et.set_on_spec("0:1:tag") == True
    assert et.valid() == True
    assert et.get_spec() == "0:1:tag"

    et = EdgeTag()
    assert et.set_on_spec("1:0:tag") == True
    assert et.valid() == True
    assert et.get_spec() == "1:0:tag"

def test_matches():
    et = EdgeTag(0, 1, "tag")
    assert et.matches(0, 1) == True
    assert et.matches(1, 0) == True
    assert et.matches(0, 2) == False
    assert et.matches(1, 2) == False

def test_matches_with_tag():
    et = EdgeTag(0, 1, "tag")
    assert et.matches(0, 1, "tag") == True
    assert et.matches(1, 0, "tag") == True
    assert et.matches(0, 1, "other_tag") == False
    assert et.matches(1, 0, "other_tag") == False

def test_matches_with_empty_tag():
    et = EdgeTag(0, 1, "tag")
    assert et.matches(0, 1, "") == False
    assert et.matches(1, 0, "") == False
