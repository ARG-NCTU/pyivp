import pytest
import automobile

c = automobile.Motorcycle("Yamaha")
print("Made a bike called: %s" % c.get_name())
c.ride("mullholland")

assert c.get_name() == "Yamaha"
