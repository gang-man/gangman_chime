from pybind11_helper import example

p = example.pet_store2()
print(type(p))
print(p.bark())